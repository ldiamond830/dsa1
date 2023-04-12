// PE4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	//creates first string
   char string1[100] = "supercalifragilistic";

   cout << "character count: " << strlen(string1) << endl; //prints its length

   //creates second string
   char string2[100] = "expialidocious";
    
   //adds the contents of string2 to string1
   strcat_s(string1, string2);

   //cout << string1; verified the strcat worked as intended
   int counter = 0;
   for (int i = 0; i < strlen(string1); i++)
   {
	   //checks each character to see if it's an i
	   if (string1[i] == 'i') {
		   counter++;
	   }
   }
   //prints the number
   cout << "Number of 'i's: " << counter << endl;

   //testing git issue
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
