#pragma once
#include <mutex>
class Fibonacci
{
public:
	void PrintFibNumber(int number, std::mutex* mtx);

private:
	int CalcFibNumber(int number);
};

