// MultiThreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;

void run(int c)
{
    while (c-- > 0)
        cout << c << ": Krishna" << endl;
   // this_thread::sleep_for(chrono::seconds(5));
    cout << "Thread 1 is finished" << endl;
}

void run2(int c)
{
    while (c-- > 0)
        cout << c << ": Balaram" << endl;
    // this_thread::sleep_for(chrono::seconds(5));
    cout << "Thread 2 is finished" << endl;
}

int main()
{
    cout << "Main starts";
    std::thread t1(run, 10);
    std::thread t2(run2, 10);
    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.join();


    cout << "Main ends";
    return 0;
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
