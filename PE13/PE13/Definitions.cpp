#include "Declarations.h"

int interativeCalulator(int seatCount)
{
	int numHands = 0;
	//loops through every seat in the row
	for(unsigned short i = 1; i <= seatCount; i++)
	{
		//if the seat is even adds four to the total, if the seat is odd adds three
		if (i % 2 == 0) {

			numHands += 4;

		}
		else
		{
			numHands += 3;
		}
	}

	//returns the total number of seats
	return numHands;
}

int recursiveCalculator(int seatCount)
{
	//check to see if there are still seats that haven't been recursed through
	if (seatCount <= 0) 
	{
		return 0;
	}

	//if the remaining seat is even adds 4 to the total and recurses to the next seat 
	if (seatCount % 2 == 0) {

		return 4 + recursiveCalculator(seatCount - 1);
	}
	//otherwise adds three before continuing to recurse to the next seat
	else {
		return 3 + recursiveCalculator(seatCount - 1);
	}
}

int formulaCalculator(int seatCount)
{
	//for an even number of seats 1/2 should be even and 1/2 should be odd so multiplying these by the number of hands in each seat and adding them gives the answer
	if (seatCount % 2 == 0) {

		return (seatCount / 2 * 3) + (seatCount / 2 * 4);
	}
	//same as even formula but adds on an extra 3 for the last seat in an odd sequence
	else {
		return (seatCount / 2 * 3) + (seatCount / 2 * 4) + 3;
	}

}