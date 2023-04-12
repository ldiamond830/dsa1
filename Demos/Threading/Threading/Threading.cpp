// Threading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "Fibonacci.h"
#include <vector>
#include <mutex>
#include <future>
using namespace std;

void printHello() 
{
    cout << "Hello" << endl;
}

void printGoodbye()
{
    cout << "Goodbye" << endl;
}

void printInfo(int info, mutex* mtx)
{
    //prevents the code from printing mutliple lines simulatiously by only allowing the the next thread to get called when the mutex is open
    mtx->lock();
    cout << "thread #" << info << endl;
    mtx->unlock();
}

void testFuture(promise<int>* promiseObj) {

    cout << "Starting Thread" << endl;

    this_thread::sleep_for(6s);

    //a value has been calculated that we can send back
    promiseObj->set_value(45);

    this_thread::sleep_for(6s);
    cout << "Ending thread" << endl;
}

int main()
{
    
    Fibonacci fib = Fibonacci();
    vector<thread*> fibThreads;
    /*
    //fib.PrintFibNumber(45);
    //runs this really slow method in the background so it doesn't delay the rest of the code
    //thread fibThread = thread(&Fibonacci::PrintFibNumber, fib, 45);
    
    

    for (int i = 1; i < 46; i++) 
    {
        fibThreads.push_back(new thread(&Fibonacci::PrintFibNumber, fib, i));
    }


    //calls the two methods in order
    printHello();
    
    printGoodbye();

    //calls the two methods at roughtly the same time
    thread helloThread = thread(printHello);
    thread goodbyeThread = thread(printGoodbye);

    //pauses the main thread (or whatever thread .join() is called from) until the joined thread has finished 
    //in order to prevent an error where main is finished and starts cleaning itself up before the threads have finished
    //a practicle application of this in games is to conduct multiple processes simulataniously in a loading screen and have them all finish before restarting gameloop
    helloThread.join();
    goodbyeThread.join();
    //fibThread.join();


    for (int i = 1; i < 46; i++)
    {
        fibThreads[i - 1]->join();
        delete fibThreads[i - 1];
        fibThreads[i - 1] = nullptr;
    }
    */
    mutex mtx;

    

    vector<thread> infoThreads;
    //advanced threading
    for (int i = 1; i < 46; i++)
    {
        fibThreads.push_back(new thread(&Fibonacci::PrintFibNumber, fib, i, &mtx));
        //infoThreads.push_back(thread(printInfo, i, &mtx));
    }


    for (int i = 0, size = fibThreads.size(); i < size; i++)
    {
        fibThreads[i]->join();
    }
    
    /*
    //promise - assumption that a value will exist at somepoint
    //future - the value that fufills the promise

    promise<int> promiseObject;
    future<int> futureObject = promiseObject.get_future();

    thread futureThread = thread(testFuture, &promiseObject);
    cout << "Waiting for thread" << endl;

    //promiseObject.get_future().get() is also valid
    cout << futureObject.get() << endl;

    futureThread.join();
    */
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
