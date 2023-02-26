/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 1
	*Description: program to practice 135, functions, loops, files, if 
	*Input: file name, user input for menu, words
	*Output: unigram, bigram, index, log
  */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
//declared constants
const int ARRAYMAX = 50000;

//function prototypes
int readData(ifstream& , string[], int&);
void cleanUp(string[], int&);
int getLongestWord(string [], int& );
void makeLower(string& str);
void generateUnigrams(struct Unigram[], int&, string[], int );
void generateBigrams(struct Bigram[], int&, string[], int );
void sortGms(struct Unigram [], int);
void sortBms(struct Bigram [], int);
int inList(string , struct Unigram [],int);
int inList(string , string , struct Bigram [],int );
void write1Gmslog(struct Unigram[], int& unigramCount);
void write2Gmslog(struct Bigram[], int& );


//struct for unigrams 
struct Unigram{
	string word;
	int frequency = 0;
};

//struct for bigrams
struct Bigram{
	string word1;
	string word2;
	int frequency = 0;
};


int main(int argc, char* argv[]) {
	//declared vars
	ifstream iFile;
	string wordArr[ARRAYMAX];
	Unigram unigrams[ARRAYMAX];
	Bigram  bigrams[ARRAYMAX];
	int unigramCount, bigramCount = 0;
	int wordCount = 0;
	int longestIndex = 0;
	int uniIndex, biIndex, inputIndex = 0;
	string file, input, input2, header;

	//checks if there is no text file with a.out
	if(argc == 2){
		iFile.open(argv[1]);
		file = argv[1];
	}else{
		//if no file, outputs error message & terminates
		cout << "Invalid Arguments" << endl;
		cout << "Usage: " << argv[0] << " filename" << endl;
		return 0;
	}
  
	header = "********************************************************";
	cout << header << endl;
	cout << "Array Size: 50000" << endl;
	cout << "Opening File: " << '\"' << file << '\"' << endl;

	//call to read in data
	wordCount = readData(iFile, wordArr, wordCount);
	//call to clean up data 
	cleanUp(wordArr, wordCount);
	//call to find longest word
	longestIndex = getLongestWord(wordArr, wordCount);
	//output longest word
	cout << "Longest Word: ";
	cout << '\"' << wordArr[longestIndex] << '\"' << endl;
	//create unigrams 
	generateUnigrams(unigrams, unigramCount, wordArr, wordCount);
	//create bigrams 
	generateBigrams(bigrams, bigramCount, wordArr, wordCount);


	do{
		//output menu options 
		cout << "Commands" << endl;
		cout << "Unigram: search for unigram" << endl;
		cout << "Bigram : search for bigram" << endl;
		cout << "Save : save 1gms.txt and 2gms.txt" << endl;
		cout << "Index : print index of unigram or bigram" << endl;
		cout << "Quit/q : terminate program" << endl;
		//get user choice
		cin >> input;
		cout << endl;
		//call to lower it 
		makeLower(input);

		//check if user entered correctly
		if(cin.fail()){
			cin.clear();
			cin.ignore(40, '\n');
			break;
		}
    
		//for each menu option
		switch(input[0]){
			case 'u':{
				//for unigram 
				if(input == "unigram"){
					//prompt 
					cout << "Enter Word to Search: ";
					cin >> input;

					//check if input was good 
					if(cin.fail()){
						cin.clear();
						cin.ignore(40, '\n');
						break;
					}

					cout << endl;
					//lowercase input
					makeLower(input);

					cout << "Searching for " << input << "..." << endl;

					//call to search for index from unigrams arr
					uniIndex = inList(input, unigrams, unigramCount);

					//if unigram not found 
					if(uniIndex <= -1 || uniIndex > ARRAYMAX){
						cout << "Unigram Not Found." << endl;
						break;
					}
			
					//output 
					cout << "Unigram Found at Index: ";
					cout << uniIndex << " with frequency of " << unigrams[uniIndex].frequency;
					cout << endl;
					break;
			
				}else{
					//if not unigrams
					cout << "Invalid entry. Try again." << endl;
					cin.clear();
					cin.ignore(40, '\n');
					break;
				}
        
			}
			case 'b':{
				//for bigram
				if(input == "bigram"){
					//prompt for 1st word 
					cout << "Enter Word1 to Search: ";
					cin >> input;

					//check if input good 
					if(cin.fail()){
						cin.clear();
						cin.ignore(40, '\n');
						break;
					}

					cout << endl;
					//prompt for 2nd word 
					cout << "Enter Word2 to Search: ";
					cin >> input2;

					//check if input good 
					if(cin.fail()){
						cin.clear();
						cin.ignore(40, '\n');
						break;
					}

					cout << endl;
					//lowercase inputs 
					makeLower(input);
					makeLower(input2);

					//output 
					cout << "Searching for " << input << " " << input2 << "..." << endl;

					//call to search for index from bigrams arr 
					biIndex = inList(input, input2, bigrams, bigramCount);

					//check if in bigrams arr 
					if(biIndex <= -1 || biIndex > ARRAYMAX){
						cout << "Bigram Not Found." << endl;
						break;
					}
					
					//output
					cout << "Bigram Found at Index: ";
					cout << biIndex << " with frequency of " << bigrams[biIndex].frequency;
					cout  << endl;
					break;
				}else{
					//if not unigrams
					cout << "Invalid entry. Try again." << endl;
					cin.clear();
					cin.ignore(40, '\n');
					break;
				}
			}
			case 's':{
				//for save 
				if(input == "save"){
					//output 
					cout << "Writing Log to " << '\"' << "1gms.txt" << '\"' <<endl;
					cout << "Writing Log to "  << '\"' << "2gms.txt" << '\"' <<endl;

					//call to func to write unigrams 
					write1Gmslog(unigrams, unigramCount);
					//call to func to write bigrams 
					write2Gmslog(bigrams, bigramCount);
					break;
				}else{
					//if not save 
 					cout << "Invalid entry. Try again." << endl;
					cin.clear();
					cin.ignore(40, '\n');
					break;
				}
			}
			case 'i':{
				//for index 
				if(input == "index"){
					//prompt user 
					cout << "Enter Index: ";
					cin >> inputIndex;
					cout << endl;
         
					//check if input good 
					if(cin.fail()){
						cin.clear();
						cin.ignore(40, '\n');
						break;
					}

					//prompt user 
					cout << "Unigram or Bigram?: ";
					cin >> input;

					//check if input good 
					if(cin.fail()){
						cin.clear();
						cin.ignore(40, '\n');
						break;
					}
         
					//check if index in arr 
					if(inputIndex <= -1 || inputIndex > ARRAYMAX){
						cin.clear();
						cin.ignore(40, '\n');
						cout << "Invalid Index: " << inputIndex;
						cout << "." << endl;
						break;
					}

					cout << endl;
					cout << endl;
					//lowercase output 
					makeLower(input);

					//for unigrams 
					if(input == "unigram"){
						//output word & freq
						cout << "Index "<< inputIndex<< ": ";
						cout << '\'' << unigrams[inputIndex].word << '\'';
						cout << " with a frequency of ";
						cout << unigrams[inputIndex].frequency;
						cout << "." << endl;
					}else if(input == "bigram"){
						//for bigrams output 
						cout << "Index "<< inputIndex<< ": ";
						cout << '\'' << bigrams[inputIndex].word1;
						cout << " " << bigrams[inputIndex].word2 << '\'';
						cout << " with a frequency of ";
						cout << bigrams[inputIndex].frequency;
						cout << "." <<endl;
					}
					break;
				}else{
					//if not save 
 					cout << "Invalid entry. Try again." << endl;
					cin.clear();
					cin.ignore(40, '\n');
					break;
				}
			}
			case 'q':{
				//for quit 
				if(input == "quit" || input == "q"){
					cout << "Goodbye!" << endl;
					cout << header << endl;
					//quit program 
					return 0;
				}else{
					cout << "Invalid entry. Try again." << endl;
					break;
				}
			}
			default:{
				//if not any menu selection
				cout << "Invalid entry. Try again." << endl;
				break;
			}
		}

	//loop until user enters quit 
	}while(input != "q" || input != "quit");

}
 

/*
  * function_identifier: reads in the data
  * parameters: iFile, word array, word count 
  * return value: word count 
  */
int readData(ifstream& iFile, string wordArr[],int& wordCount){
	string word;
	//loop through whole array 
	for(int i= 0; i < ARRAYMAX; i++){
		//read in one word
		iFile >> word;
		//read until end of file 
		if(iFile.eof()){
			break;
		}
		//increment word count 
		wordCount++;
		//puts word into word array
		wordArr[i] = word;
	}
  
	//close file 
	iFile.close();
	cout << "Finished Reading " << wordCount << " words. Closing File." << endl;

	return wordCount;
}


/*
  * function_identifier: find longest word 
  * parameters: word array, word count 
  * return value: returns index of longest word 
  */
//gets longest word
//pass by &?
int getLongestWord(string wordArr[], int& wordCount){
	int index = 0;
	string longest;

	//loop through word arr 
	for(int i = 0; i < wordCount; i++){
		//check for greatest size 
		if(longest.size() < wordArr[i].size()){
			longest = wordArr[i];
			index = i;
		}
	}

	return index;
}


/*
  * function_identifier: lowercase word, remove punctuation, NONALPHA numbers
  * parameters: string array, word count
  * return value: no return value 
  */
void cleanUp(string word[], int& wordCount){
	//declared vars 
	string temp, temp2, input;
	ofstream oFile;
	bool hasNum, notCleaned = false;

	//prompt user 
	cout << "Log cleanup? Y/n: ";
	cin >> input;
	cout << endl; 
	makeLower(input);

	//check user input for yes 
	if(input == "y"){
		//output 
		cout << "Writing Log to " << '\"' << "ast1log.txt" << '\"' << endl; 
		oFile.open("ast1log.txt");
		oFile << "Nonalphanumeric Replacement Log file:" << endl;
	}

	//loop through to remove punctuation
	for(int i = 0; i < wordCount; i++){
		//call func to lowercase
		makeLower(word[i]);
		//reset
		temp = "";
		temp2 = "";
		notCleaned = false;
		hasNum = false;

		//loop through each character
		for(unsigned int j = 0; j < word[i].length(); j++){
			//uncleaned version with punctuation
			if(word[i][j] < 'a' && !(word[i][j] >= '0' && word[i][j] <= '9') ){
				notCleaned = true;
				temp2 = word[i];
			}
			//check for letters 
			if(word[i][j] >= 'a' && word[i][j] <= 'z'){ 
				temp = temp + word[i][j];
			} 
			//check for numbers 
			if(word[i][j] >= '0' && word[i][j] <= '9'){
				hasNum = true;
				temp = temp + word[i][j];
			}
			if(notCleaned){
				continue;
			}  
		}
	
		//set word arr to temp
		word[i] = temp;

		//has num && has no punctuation 
		if(hasNum && !notCleaned){
			//save word to temp2 & set to nonalpha 
			temp2 = word[i];
			word[i] = "NONALPHA";
		}
  
		//if input is n
		if(input == "n"){
			//has num & no punct
			if(hasNum && !notCleaned){
				temp2 = word[i];
				word[i] = "NONALPHA";
			}
			//if only has num 
			if(hasNum){
				word[i] = "NONALPHA";
			}
		}

		//if user selected yes
		if(input == "y"){
			//has num & no punct
			if(hasNum && !notCleaned){
				//write out 
				oFile << temp2 <<  " --> ";
				word[i] = "NONALPHA";
				oFile << word[i] << endl;
			}
			//if still has punct
			if(notCleaned){
				//write out 
				oFile << temp2 << " --> ";
				oFile << word[i] << endl;
				//if does have num
				if(hasNum){
					//write out 
					oFile << word[i] <<  " --> ";
					word[i] = "NONALPHA";
					oFile << word[i] << endl;
				}
			}
		}
	}
}



//check if already in array
/*
  * function_identifier: checks if word is already in unigram arr
  * parameters: word, struct unigram arr, count 
  * return value: returns index if found
  */
int inList(string word, struct Unigram list[], int count){
	//default is not found 
	int index = -1;
	for(int i = 0; i < count; i++){
		//if string present returns index
		if(list[i].word == word){
			index = i;
		}
	}

	return index;
}


/*
  * function_identifier: checks if word is already in bigram arr
  * parameters: word, struct bigram arr, count 
  * return value: returns index if found
  */
int inList(string word1, string word2, struct Bigram list[],int count){
	//default is not found 
	int index = -1;
	for(int i =0; i < count; i++){
		//if string present just returns 
		if(list[i].word1 == word1 && list[i].word2 == word2){
			index = i;
		}
	}

	return index; 
}


/*
  * function_identifier: sort unigrams based on freq, descending 
  * parameters: struct unigram arr, word count 
  * return value: nothing 
  */
void sortGms(struct Unigram unigram[], int wordCount){
	bool swapped = false;
	int num = 0;
	Unigram temp;
	num = wordCount;

	do{
		//reset swapped 
		swapped = false;
		//loop through unigram arr 
		for(int i = 0; i < wordCount; i++){
			//check if unigram freq is less than next one 
			if(unigram[i].frequency < unigram[i+1].frequency){
				//saves into temp 
				temp = unigram[i+1];
				//saves next uni to uni before 
				unigram[i+1] = unigram[i];
				//uni then equals temp
				unigram[i]= temp;
				//sets swapped to true 
				swapped = true;
			} 
		}
		num--;

	//loop while swapped is true;
	}while(swapped);
  
}


/*
  * function_identifier: sort bigrams alphabetically 
  * parameters: struct unigram arr, word count 
  * return value: nothing 
  */
void sortBms(struct Bigram bigram[], int wordCount){
	bool swapped = false;
	int i = 0;
	int num = 0;
	Bigram temp;
	num = wordCount;

	do{
		swapped = false;
		for(i = 1; i < num; i++){
			//checks if 1st word of bigram is greater than previous 
			if(bigram[i-1].word1 > bigram[i].word1){
				//saves previous into temp
				temp = bigram[i];
				//saves previous to bigram
				bigram[i] = bigram[i-1];
				//bigram now temp 
				bigram[i-1]= temp;
				swapped = true;
			}
			//checks if 2nd word of bigram is greater than previous 
			if(bigram[i-1].word1 == bigram[i].word1 && bigram[i-1].word2 > bigram[i].word2){
				//saves previous into temp
				temp = bigram[i];
				//saves previous to bigram
				bigram[i] = bigram[i-1];
				//bigram now temp 
				bigram[i-1]= temp;
				swapped = true;
			}
		}
   		 num--;
	//loop while swapped is true
	}while(swapped);
}


//generate array of unigrams 
//uses sort unigram fun
/*
  * function_identifier: creates unigram arr 
  * parameters: word arr, word count, struct unigram arr, unigram count 
  * return value: nothing
  */
void generateUnigrams(struct Unigram unigram[], int &unigramCount, string word[], int wordCount){ 
	string inputWord;
	int index = 0;

	//loop through arr 
	for(int i = 0; i < wordCount; i++){
		//call to func to find check if word is in arr 
		index = inList(word[i], unigram, wordCount);
		//if it is there increment freq
		if(index != -1){
			unigram[index].frequency+=1;
		}else{
			//adds to unique arr & update count 
			unigramCount++;
			unigram[unigramCount].word = word[i];
			//increment freq
			unigram[unigramCount].frequency+=1;
		}
	}

	//call to func to sort unigrams 
	sortGms(unigram, unigramCount);
}


//generate array of bigrams
//uses sort bigram func
/*
  * function_identifier: creates bigram arr 
  * parameters: word arr, word count, struct bigram arr, bigram count 
  * return value: nothing
  */
void generateBigrams(struct Bigram bigram[], int &bigramCount, string word[], int wordCount){
	int index = 0;
	string bigramCom;

	//loop through arr 
	for(int i = 0; i < wordCount; i++){
		//call to func to find check if word is in arr 
		index = inList(word[i], word[i+1], bigram, wordCount);
		//if it is there increment freq
		if(index != -1){
			bigram[index].frequency+=1;
		}else{
			//adds to unique arr & update count 
			bigramCount++;
			bigram[bigramCount].word1 = word[i];
			bigram[bigramCount].word2 = word[i+1];
			//increment freq
			bigram[bigramCount].frequency+=1;
		}
	}

	//call to func to sort bigrams 
	sortBms(bigram, bigramCount);
}


/*
  * function_identifier: prints out unigrams to file 
  * parameters: unigram arr, unigram count 
  * return value: nothing 
  */
void write1Gmslog(struct Unigram unigram[], int& unigramCount){
	ofstream oFile;

	//opens output file 
	oFile.open("1gms.txt");
	//write out to file 
	oFile << unigramCount << endl;

	//loop through arr 
	for(int i = 0; i < unigramCount; i++){
		//output word & freq
		oFile << unigram[i].word << " ";
		oFile << unigram[i].frequency << endl;
	}

	oFile.close();
}

/*
  * function_identifier: brief description of what the function does.
  * parameters: what to pass into the function
  * return value: what the function returns, if any
  */
void write2Gmslog(struct Bigram bigram[], int& bigramCount){
	ofstream oFile;

	//opens output file 
	oFile.open("2gms.txt");
	//write out to file 
	oFile << bigramCount << endl;

	//loop through arr 
	for(int i = 1; i < bigramCount; i++){
		//output word & freq
		oFile << bigram[i].word1 << " ";
		oFile << bigram[i].word2 << setw(4);
		oFile << bigram[i].frequency << endl;
	}
	oFile.close();
}

/*
  * function_identifier: make string lowercase 
  * parameters: string 
  * return value: nothing 
  */
void makeLower(string& str){
	//var for string size
	int string = str.size();
	//loop until string size 
	for(int i = 0; i < string; i++){
		//convert all letters to lower
		str[i] = tolower(str[i]);
	}
}
