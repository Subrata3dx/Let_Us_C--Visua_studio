// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>
using namespace std;


class A
{
public:
    A()
    {
        cout << endl << "Constructor A";
    }
    ~A()
    {
        cout << endl << "Destructor A";
    }
    void fun()
    {
        cout << endl<<"From fun()";
    }
};


int main()
{       
    unique_ptr<A> ptr1(new A);
    shared_ptr<A> ptr2(new A);
    shared_ptr<A> ptr3(new A);
    weak_ptr<A> ptr4;

    cout << endl<<"address of unique_ptr: " << ptr1.get();
    ptr2 = move(ptr1);

    if (!ptr1)
        cout << endl << "ptr1 is not alive";

    cout << endl<<"address of shared_ptr2: " << ptr2.get();

    ptr3 = ptr2;

    if (!ptr2)
        cout << endl << "ptr2 is not alive";
    cout << endl << "address of shared_ptr3: " << ptr3.get();
    ptr2->fun();
    ptr4 = ptr2;
    if(!ptr4.expired()) //returns if the referred pointer is expired or not
        cout << endl << "ptr2 is  alive";
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
