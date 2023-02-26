/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 10
	*Description: program for linked stacks and queues, makefile, 
	*Input: audio file to be reversed and output file to write to 
	*Output: reversed audio file 
*/

//  Main program
//		Reverse an audio file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linkedStack.h"
#include "linkedQueue.h"

using namespace std;

int main(int argc, char *argv[])
{
  // declared vars 
  ifstream inFile;
  ofstream outFile;
  string line; 
  int sampleRate = 0;

// *****************************************************************
//	Check and process command line arguments.
//		Usage: ./reverse <inputFile> <outputFile>
//	 NOTE:	Must exit with "return EXIT_SUCCESS" even if there
//			is an error.

	// Error message strings provided below

  // no arguments -> usage message
  // just the ./reverse part
  if(argc == 1){
    cout << "Usage: ./reverse <inputFile> <outputFile>" << endl;
    return EXIT_SUCCESS;
  }
  // incorrect number of arguments, just error out.
  if(argc != 3){
    cout << "Error, must provide input and output file names." << endl;
    return EXIT_SUCCESS;
  }

  // open 2nd argument file 
  inFile.open(argv[1]);

  // check argument 1, input file, by attempting to open, read access
  if(!inFile.is_open()){ // check if infile opened
    cout << "Error, unable to open input file: " << argv[1] << endl;
    return EXIT_SUCCESS;
  }

  // open output file 
  outFile.open(argv[2]);

	// check argument 2, output file, by attempting to open, write acess
  if(!outFile.is_open()){ // check if outfile opened
    cout << "Error, unable to open output file: " << argv[2] << endl;
    return EXIT_SUCCESS;
  }

  
// *****************************************************************
//  Headers...

	string	bars(50, '-');
	cout << bars << endl << "CS 202 - Assignment #10" << endl;
	cout << "Audio Reversal Program" << endl << endl;

// *****************************************************************
//	Handle audio file header lines
	// ensure header has correct title
	// get sample rate from header
	// read second header line and write to output file.

  //  read initial header line
  getline(inFile, line);
  //  verify format (i.e, "; Sample Rate" is present)
  if(line.find("; Sample Rate") == string::npos){
    cout << "Invalid audio data file" << endl;
    return EXIT_SUCCESS;
  }

  // write to output file.
  outFile << line << endl;

  // erase 
  line.erase(line.find(";"), line.find("te")+2);
  //  extract sample rate, convert to integer
  sampleRate = stoi(line);

  // read second header line and write to output file.
  getline(inFile, line);
  outFile << line << endl;

// *****************************************************************
//	Process and audio data file.

	// declare linked stack and linked queue
	//	use to sampleRate/2 for the node array sizes
	linkedQueue<double> dQueue(sampleRate/2);
	linkedStack<double> dStack(sampleRate/2);
	double	sample1 = 0.0, sample2 = 0.0;

	// read input file, store samples in output file 
  while(true){
    // read in & store into doubles 
    inFile >> sample1 >> sample2;
    // check if at end of file 
    if(inFile.eof()){
      break;
    }
    // add to queue
    dQueue.addItem(sample1);
    // add to stack 
    dStack.push(sample2);
  }

	// show count of all samples
	cout << "Count = " << dQueue.queueCount() << endl;

	// get samples, write to output file
	//	output format:
	//		outFile << "  " << sample1 << "  " << sample2 << endl;
  // loop until queue is empty 
  while(!dQueue.isEmptyQueue()){
    // output to output file
    outFile << "  " << dQueue.front() << "  " << dStack.top() << endl;
    // delete to get next item
    dQueue.deleteItem();
    dStack.pop();
  }

// *****************************************************************
//  All done.
//		close file and show final message.
	inFile.close();
	outFile.close();

	cout << bars << endl << "Reversal completed." << endl;

	return	EXIT_SUCCESS;
}