// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
using namespace std;
//rules of recursion
//1) Recursive call that moves toward the terminating case
//2) Terminating case.

int factorial(int number);
int factorialRecursive(int number);

int fibonacci(int number, int* cache);
int fibRecursive(int number, int* count, int* cache);

int main()
{
    cout << "Factorial(0) = " << factorial(0) << endl;
    cout << "Factorial(10) = " << factorial(10) << endl;

    cout << "FactorialRecursive(0) = " << factorialRecursive(0) << endl;
    cout << "FactorialRecursive(10) = " << factorialRecursive(10) << endl;

    int* cache = new int[45]{ 0, 1, 1 };

    cout << "Fibonacci(4) = " << fibonacci(4, cache) << endl;
    cout << "Fibonacci(10) = " << fibonacci(10, cache) << endl;

    int count = 0;
    //clears the previosuly cached values
    delete[] cache;
    cache = new int[46]{ 0,1,1 };

    auto start = chrono::system_clock::now();


    //cout << "Fibonacci Recursive(4) = " << fibRecursive(4, &count) << endl;
    cout << "Fibonacci Recursive(45) = " << fibRecursive(45, &count, cache) << endl;
    


    auto end = chrono::system_clock::now();

    auto duration = chrono::duration_cast<chrono::seconds>(end - start);

    cout <<"Duration: " << duration.count() << " Seconds " << endl << "Function calls: " << count << endl;

    delete[] cache;
}

int factorial(int number) 
{
    int product = 1;
    while (number > 1) {
        product *= number;
        number--;
    }

    return product;
}

int factorialRecursive(int number)
{
    //once the method recuses down to one factorial just returns 1 for the terminating case
    if (number <= 1) 
    {
        return 1;
    }

    return factorialRecursive(number - 1) * number;
}

int fibonacci(int number, int* cache)
{
    //returns previosuly calcuated values 
    if (cache[number] != 0) 
    {
        return cache[number];
    }

    for(int i = 2; i <= number; i++)
    {
        if (cache[i] != 0) {
            continue;
        }

        cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[number];

   // int oneBack = 1;
   // int twoBack = 1;
   // int current;
   //
   // for (int i = 2; i < number; i++)
   // {
   //     current = twoBack + oneBack;
   //
   //     twoBack = oneBack;
   //     oneBack = current;
   // }
   //
   // return current;
}  


int fibRecursive(int number, int* count, int* cache) 
{
    (*count)++;
    

    if (cache[number] != 0) {
        return cache[number];
    }

    cache[number] = fibRecursive(number - 1, count, cache) + fibRecursive(number - 2, count, cache);

     

    return cache[number];
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
