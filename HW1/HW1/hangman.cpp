#include "hangman.h"
#include <iostream>
#include <cstring>

using namespace std;


bool checkIfContains(char letter[], char word[])
{
	//checks if there are any of the guessed letter in the word and if so returns true
	if (strchr(word, letter[0])) {
		return true;
	}
	return false;
}

void updateWord(char letter[], char word[], char output[]) {
	//loops through the answer word and inputs each copy of the letter into the guess holder
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == letter[0])
		{
			output[i] = letter[0];
		}
	}
}


void showSolveDisplay(char word[], char guesses[]) {
	//printsa out each letter the user has guessed that wasn't a part of the word
	cout << "Incorrect Letters Guessed: ";
	for (int i = 0; i < strlen(guesses); i++) {
		cout << guesses[i];
	}
	cout << endl;
	//prints out each letter or blank space in the word the user is guessing
	cout << "Word: ";
	for (int i = 0; i < strlen(word); i++) {
		cout << word[i];
	}
	cout << endl;
}

void showGallows(int guessesRemaining) {
	//prints out the state of the gallows
	switch (guessesRemaining)
	{
		//loss state
		case 0:
		cout << "______ \n"
			<< "|   |\n"
			<< "|   O\n"
			<< "|  /|\\\n"
			<< "|  / \\\n " << endl;
		break;
		//adds another part of the hangman for each wrong guess
		case 1:
			cout << "______ \n"
				 << "|   |\n"
				 << "|   O\n" 
				 << "|  /|\\\n" 
				 << "|  / \n " << endl;
			break;
			case 2:
			cout << "______ \n"
				<< "|   |\n"
				<< "|   O\n"
				<< "|  /|\\\n"
				<< "|  \n " << endl;
			break;
			case 3:
				cout << "______ \n"
					<< "|   |\n"
					<< "|   O\n"
					<< "|  /|\n"
					<< "|  \n " << endl;
				break;
			case 4:
				cout << "______ \n"
					<< "|   |\n"
					<< "|   O\n"
					<< "|   |\n"
					<< "|  \n " << endl;
				break;
			case 5:
				cout << "______ \n"
					<< "|   |\n"
					<< "|   O\n"
					<< "|   \n"
					<< "|  \n " << endl;
				break;
			case 6:
				cout << "______ \n"
					<< "|   |\n"
					<< "|   \n"
					<< "|   \n"
					<< "|  \n " << endl;
				break;
			case 7:
				cout << "______ \n"
					<< "|   \n"
					<< "|   \n"
					<< "|   \n"
					<< "|  \n " << endl;
				break;
				//catch all for guess numbers that aren't 7-0 does nothing
			default:
				break;
	}
}