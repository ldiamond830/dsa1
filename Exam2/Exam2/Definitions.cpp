#include "Declarations.h"
#include <iostream>
using namespace std;
//returns a random int between two bounds
int generateRandom(int max, int min) 
{
	int temp = (max * 2) + 1;
	float returnValue;

	//check for negative ranges
	if (min < 0) 
	{
		returnValue = (rand() % temp) + min;
	}
	else 
	{
		returnValue = (rand() % temp) - min;
		
	}


	return (int)returnValue;

}