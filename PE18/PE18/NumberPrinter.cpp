#include "NumberPrinter.h"
#include <iostream>

using namespace std;
NumberPrinter::NumberPrinter(int _number)
{
	number = _number;
}

void NumberPrinter::Print()
{
	for (short i = 0; i < 50; i++)
	{
		cout << number << " ";
	}
	cout << endl;
}
