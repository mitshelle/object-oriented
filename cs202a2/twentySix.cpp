/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 2
	*Description: program to practice classes 
	*Input: bank amount, display details 
	*Output: dice game, inital bank amount, current bank amount, score 
*/

#include <iostream>
#include "twentySix.h"

using namespace std;

// constructor 
// where initialize class vars 
twentySix::twentySix(int bankAmount){

	// sets bank amount from user 
	initialBank = bankAmount;
	// sets to initial bank
	currentBank = initialBank;
	diceRolls[12][9] = {};
	displayGame = true;
	pointValue = 0;
	currentScore = 0;
	currentPayout = 0;
}


/*
* function_identifier: reads in bank amt from user & checks if btwn 10 & 200
* parameters: nothing
* return value: nothing
*/
void twentySix::readInitialBankAmount(){

	do{ // loop unitl input is btwn 10 & 200 
  
		// output 
		cout << "Initial Bank amount must be between 10 and 200" << endl;
		cout << "Enter Initial bank Amount: ";
		// get user input
		cin >> initialBank;

		// check if bank amount is btwn 10 & 200 
		if(initialBank >= MIN_BANK && initialBank <= MAX_BANK ){
			// sets current bank to initial bank
			currentBank = initialBank;
		}else{ // if not btwn 10 & 200, output error
			cout << "Error, invalid bank amount, please re-enter." << endl;
		}
	}while(initialBank < MIN_BANK || initialBank > MAX_BANK );

	return;
}


/*
* function_identifier: sets bank amount from user to initial & current bank
* parameters: bankAmount from user 
* return value: nothing
*/
void twentySix::setInitialBankAmount(int bankAmount){
	// check if bank amount btwn 10 & 200 
	if(bankAmount >= MIN_BANK && bankAmount <= MAX_BANK){
		// sets bank amt to intial bank
		initialBank = bankAmount;
		// sets current bank to initial 
		currentBank = initialBank;
	}else{ // if not btwn 10 & 200, output error message
		cout << "Error, invalid bank amount." << endl;
		cout << "Error, invalid initial bank amount value." << endl; 
		cout << "No changes made." << endl;
	}

	return;
}


/*
* function_identifier: returns initial bank amount 
* parameters: nothing
* return value: initial bank amount 
*/
int twentySix::getInitialBankAmount() const{
  
	// gets the initial bank amt
	return initialBank;
}


/*
* function_identifier: returns current bank amount 
* parameters: nothing
* return value: current bank amount 
*/
int twentySix::getBankAmount() const{

	// gets the current bank amt
	return currentBank;
}


/*
* function_identifier: sets bool according to user input (yes/no)
* parameters: display input from user 
* return value: nothing
*/
void twentySix::setDisplayMode(bool display){

	// sets displayGame to user input
	displayGame = display;

	return;
}


/*
* function_identifier: calls yesOrNo func to prompt user, 
*   sets twentySix class displayGame var to true if y, false if n, 
* parameters: nothing
* return value: nothing
*/
void twentySix::readDisplayMode(){
	// vars
	string prompt;
	bool answer = true;

	// prompt to pass to yesOrNo func
	prompt =  "Display Game Details? (Y/y/N/n): ";
	// sets answer to returned bool from yesOrNo
	answer = yesOrNo(prompt);
  

	if(answer){ // check if answer true, sets displayGame to true
		displayGame = true;
	}else{ // check if answer fale, sets displayGame to false
		displayGame = false;
	}

	return;
}


/*
* function_identifier: calls yesOrNo func to prompt user, record input 
* parameters: nothing
* return value: answer, if yes answer is true, if no answer is false
*/
bool twentySix::playOn() const{
	// vars
	bool answer = true;
	string prompt;

	// prompt to pass to yesOrNo func
	prompt = "Play Another Round? (Y/y/N/n): ";
	// sets answer to returned bool from yesOrNo
	answer = yesOrNo(prompt);

	// return bool 
	return answer;
}


/*
* function_identifier: plays twenty six game, 
*   updates vars according to game rules 
* parameters: nothing
* return value: nothing
*/
void twentySix::playRound(){

	// decrement currentBank each played round
	currentBank-=1;

	// sets point value to random num each round 
	pointValue = rand() % 6 +1;

	// loop through dice rolls arr and sets each to rand num
	for(int i = 0; i < 13; i++){ // rows 
		for(int j = 0; j < 10; j++){ // columns
			// sets to rands num 
			diceRolls[i][j] = rand() % 6 +1;
			// if element equal to point value
			if(diceRolls[i][j] == pointValue){
				// increment score, counts how many times point value shows up 
				currentScore++;
			}
		}
	}

	// payout 
	if(currentScore <= 10){ 
		// if amount of times num shows up is 10 or less, add 10 to current bank
		currentPayout = 10;
		currentBank = currentBank + 10;
	}else if(currentScore == 13){
		// if amount of times num shows up is 13, add 5 to current bank
		currentPayout = 5;
		currentBank = currentBank + 5;
	}else if(currentScore == 26){
		// if amount of times num shows up is 26, add 4 to current bank
		currentPayout = 4;
		currentBank = currentBank + 4;
	}else if(currentScore == 27){
		// if amount of times num shows up is 27, add 5 to current bank
		currentPayout = 5;
		currentBank = currentBank + 5;
	}else if(currentScore == 28){
		// if amount of times num shows up is 28, add 6 to current bank
		currentPayout = 6;
		currentBank = currentBank + 6;
	}else if(currentScore == 29){
		// if amount of times num shows up is 29, add 8 to current bank
		currentPayout = 8;
		currentBank = currentBank + 8;
	}else if(currentScore == 30){
		// if amount of times num shows up is 30, add 10 to current bank
		currentPayout = 10;
		currentBank = currentBank + 10;
	}else{
		// if not any, adds nothing 
		currentPayout = 0;
	}

  
	if(displayGame){ // display game is true
		// call to func to display game 
		showGame();
	}

	// reset vars for each round 
	currentScore = 0;
	currentPayout = 0;

	return;
}


/*
* function_identifier: prompts user from passed string, records input 
* parameters: string 
* return value: true if answer is y, false if answer n (bool)
*/
bool twentySix::yesOrNo(string prompt) const{
	// declared vars 
	bool answer = false;
	char input = 0;

	do{ // loop until input is y/n/N/Y
		// output passed prompt
		cout << prompt;
		// get input 
		cin >> input;

		if(input == 'y' || input == 'Y'){ // if yes, set answer to true
			answer = true;
			break;
		}
		if(input == 'n' || input == 'N'){ // if no, set asnwer to false
			answer = false;
			break;
		}
		if(input != 'y' || input != 'Y' || input != 'n' || input != 'N'){ 
			// if not either, output error message 
			cout << "Error, must respond 'Y', 'y', 'N', or 'n'." << endl;
			cout << "Please try again." << endl;
		}

	}while(input != 'y' || input != 'Y' || input != 'n' || input != 'N');
  
	// return bool 
	return answer;
}


/*
* function_identifier: display game details 
* parameters: nothing
* return value: nothing
*/
void twentySix::showGame() const{
	// output header 
	cout << endl << "*********************************" << endl; 
	cout << "Twenty-Six Game - Round Results: " << endl;
	cout << "Dice Rolls: " << endl;

	for (int i=0; i<13; i++) { // output dice rolls 
		for (int j=0; j<10; j++){
			cout << "   " << diceRolls[i][j];
		}
		cout << endl;
	}

	// output player details 
	cout << endl;
	cout << "Initial Bank:   " << initialBank << endl;
	cout << "Point Value:    " << pointValue << endl;
	cout << "Score:          " << currentScore << endl;
	cout << "Payout Amount:  " << currentPayout;
  
	if (currentPayout > 0){
		cout << "     You won!  :-)" << endl;
	}else{
		cout << "     You lost.  :-(" << endl;
	}
	cout << "Current Bank:   " << currentBank << endl;
	cout << endl;

	return;
}