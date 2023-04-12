// PE16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    //creating the file stream and a new text file
    ofstream writer = ofstream("text.txt");
    //entering text into the file
    writer << "Line 1" << endl << "Line 2 Line 2" << endl << "Last line";
    //closes the file so another file stream can access it
    writer.close();

    //creates an instream in binary mode
    ifstream reader = ifstream("text.txt", ios::binary);

    //reads the information in the file into a string
    string fileString = string(istreambuf_iterator<char>(reader), istreambuf_iterator<char>());
    reader.close();

    //prints the string to the console
    cout << fileString;

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
