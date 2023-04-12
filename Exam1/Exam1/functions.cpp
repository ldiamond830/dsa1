#include "Definitions.h"
#include <iostream>
using namespace std;


void averageScore(float* scores, int numScores) {

	
	float total = 0;
	float average = 0;

	//finds the sum of all the scores
	for (int i = 0; i < numScores; i++) 
	{
		total += *scores;
		//iterates to the next score
		scores++;

	}

	
	average = total / numScores;
	//prints result
	cout << "Your Average Score is: " << average << endl;


}

void highScore(float* scores, int numScores) 
{
	
	float highest = 0;
	//iterates through each value in scores and sets highest to the highest one
	for (int i = 0; i < numScores; i++)
	{
		
		if (*scores > highest) {
			highest = *scores;
		}
		scores++;
	}
	//prints results
	cout << "The highest score is: " << highest << endl;

}

void lowScore(float* scores, int numScores) 
{
	//sets lowest to a very high initial value so that any user input is basically garunteed to be less than it
	float lowest = 999999999999;
	//checks each score to see which is the lowest and stores that in lowest
	for (int i = 0; i < numScores; i++)
	{
		if (*scores < lowest) {
			lowest = *scores;
		}
		scores++;
	}
	//prints results
	cout << "The lowest Score is: " << lowest << endl;
}

void wrapper()
{

	int numScores;
	float* scores;
	bool validInput = false;

	while (!validInput)
	{
		cout << "How many scores would you like to input: ";

		cin >> numScores;
		//empties the queue cin is built on
		cin.clear();
		//removes any extra characters from the cin queue
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//requires the number of scores the user wants to have be a number greater than 0 otherwise keeps looping
		if (numScores > 0) {
			validInput = true;
		}
	}
	//allocates memory
	scores = new float[numScores];

	//inputs each value
	for (int i = 0; i < numScores; i++) {
		cout << "Input a score: ";
		cin >> scores[i];
	}
	
	
	//calls methods
	averageScore(scores, numScores);
	highScore(scores, numScores);
	lowScore(scores, numScores);

	cout << endl;
	
	//memory cleanup
	delete scores;
	scores = nullptr;

}