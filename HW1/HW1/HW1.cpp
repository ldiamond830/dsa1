// HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

#include "hangman.h"

using namespace std;

int main()
{
	
	//initiating variables
	int guesses = 7;
	bool winLoss = false;
	char guessedLetters[26] = "";
	char answer[100] = "nothing";
	char input[2] = "";
	char guessHolder[100] = "";
	bool hasWon = false;

	//fills the guess holder with underscores for each character in the answer word
	for (int i = 0; i < strlen(answer); i++) {
		guessHolder[i] = '_';
	}
	
	cout << "Let's play hangman!" << endl;
	cout << "the word has " << strlen(answer) << "letters" << endl;

	while (guesses > 0) {
		//creats a line break at the begining of each turn
		cout << endl;
		//checks if the user has guessed every letter
		if (!strchr(guessHolder, '_'))
		{
			//triggers the win message
			winLoss = true;
			//stops the loop
			guesses = -1;
			//skips over the rest of the current loop
			continue;
		}
		//gives the user information about their status in game
		cout << "Remaining guesses: "<< guesses << endl;
		showGallows(guesses);
		showSolveDisplay(guessHolder, guessedLetters);

		//prompts the user to enter a guess
		cout << "Guess a letter:";
		cin >> input[0];
		//removes any extra characters from the cin queue
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//checks if the guessed letter 
		if (checkIfContains(input, answer)) {
			//if so updates the guess holder
			updateWord(input, answer, guessHolder);
		}
		else {
			//otherwise copies the guessed letter into the list of incorrect guesses and reduces the number of remaining guesses
			strcat_s(guessedLetters, input);
			guesses--;
		}

		

	}
	//win loss conditions
		if (winLoss == true) 
		{
			cout << "The word was " << answer << endl;
			cout << "You Win" << endl;
		}
		else 
		{
			showGallows(guesses);
			cout << "The word was " << answer << endl;
			cout << "You Loose" << endl;
		}
	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
