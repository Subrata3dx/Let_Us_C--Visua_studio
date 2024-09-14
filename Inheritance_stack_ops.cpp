// Inheritance_stack_ops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class stack
{
protected:
    int top, arr[5];

public:
    stack()
    {
        top = -1;
    }
    void push(int a)
    {
        top++;
        arr[top] = a;
    }

    int pop()
    {
        return arr[top--];
        
    }
};

class stack1 :stack
{
private:
    int x;

public:
    void push(int a)
    {
        if (top == sizeof(arr))
            std::cout << ("\nStack is full.");
        else
        {
            
            stack::push(a);
        }
    }

    void pop()
    {
        if (top == -1)
            std::cout << ("\nStack is empty.");
        else
        {

            x=stack::pop();
            std::cout << "Stack top value is: " << x;
            std::cout << endl;
        }
    }
};


int main()
{
    stack1 s1;
    s1.push(10);
    s1.push(20);
    s1.pop();
    s1.pop();
    s1.pop();
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
