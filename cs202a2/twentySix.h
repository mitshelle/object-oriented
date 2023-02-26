/*
  *Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 2
	*Description: program to practice classes 
	*Input: bank amount, display details 
	*Output: dice game, initial bank amount, current bank amount, score 
*/

// header file
#include <string> 
#include <iostream>

using namespace std;

/*
	* class_identifier: play game of twenty six rolling 10 dice 13x 
	* constructors: twentySix(int = 10)
	* public functions: 
	*	void readInitialBankAmount();
		void setInitialBankAmount(int bankAmount);
		int getInitialBankAmount() const;
		int getBankAmount() const;
		void setDisplayMode(bool display);
		void readDisplayMode();
		bool playOn() const;
		void playRound();
	* static members: 
		static constexpr int MIN_BANK = 10;
		static constexpr int MAX_BANK = 200;
*/

class twentySix{
	public:  // access for everyone 
		// Constructor
		twentySix(int=10);
    
		// function prototypes 
		void readInitialBankAmount();
		void setInitialBankAmount(int bankAmount);
		int getInitialBankAmount() const;
		int getBankAmount() const;
		void setDisplayMode(bool display);
		void readDisplayMode();
		bool playOn() const;
		void playRound();

	private: // only in same class 
		// declared vars 
		int initialBank;
		int currentBank;
		bool displayGame;
		int pointValue;
		int currentScore;
		int currentPayout;
		int diceRolls[13][10];
		// constants 
		static constexpr int MIN_BANK = 10;
		static constexpr int MAX_BANK = 200;
		// function prototypes
		bool yesOrNo(string answer) const;
		void showGame() const;
};
