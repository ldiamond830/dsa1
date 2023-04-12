// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include <string>
using namespace std;
int main()
{
    //out file steam aka writer
    ofstream outFile = ofstream("text.txt"); //will attempt to create file "text.txt" if it doesn't already exist

    //if this method returns true the file is open and it is safe to interact with the file
    if (outFile.is_open()) {
        //capitalizing the first letter of every word is very important
        outFile << "Hello File IO World" << endl;
        outFile << "Hello New Line ";
        outFile << "Hello Same Line";
        
    }
    outFile.close();



    //in file stream aka reader
    ifstream inFile = ifstream("text.txt");
    
    //taking in a pointer to the begining and ending character
    //string constructor loops from thre first character until it finds the address of the last character
    string fileString = string(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>());
    inFile.close();

    cout << fileString << endl;



    string myObscuredText = "I am obscured";
    const short OBSCURE_KEY = 5713425;

    for (short i = 0; i < myObscuredText.size(); i++) {
        //uses XOR bitwise operation to store the text as seemingly random text, this way by XORing the result of this operation we can get the original text back
        myObscuredText[i] ^= OBSCURE_KEY;
    }

    outFile.open("obscured.txt");

    if (outFile.is_open()) 
    {
        outFile << myObscuredText;
    }

    outFile.close();

    inFile.open("obscured.txt");
    fileString = string(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>());
    inFile.close();

    for (short i = 0; i < fileString.size(); i++) 
    {
        //uses XOR bitwise operation to store the text as seemingly random text, this way by XORing the result of this operation we can get the original text back
        fileString[i] ^= OBSCURE_KEY;
    }

    cout << fileString << endl;

    //binary mode doesn't actually read the information in as binary, it just makes things safe for cross platform
    ifstream mapFileIn = ifstream("level1.map.txt", ios::binary);
    
    string line;
    while (mapFileIn.good()) 
    {
        getline(mapFileIn, line);
        cout << line << endl;
    }
    mapFileIn.close();
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
