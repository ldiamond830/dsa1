#include "Fibonacci.h"
#include <iostream>
#include <mutex>

void Fibonacci::PrintFibNumber(int number, std::mutex* mtx)
{
    int fibNum = CalcFibNumber(number);
    mtx->lock();
    std::cout << number << " - " << fibNum << std::endl;
    mtx->unlock();
}

int Fibonacci::CalcFibNumber(int number)
{
    if (number <= 2) 
    {
        return 1;
    }

    return CalcFibNumber(number - 1) + CalcFibNumber(number - 2);
}
