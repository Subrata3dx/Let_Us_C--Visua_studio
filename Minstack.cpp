// Minstack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
using namespace std;


class MinStack
{
public:
    MinStack()
    {

    }

    stack<int>st, mini;

//private:
    void push(int val)
    {
        st.push(val);

        if (mini.empty())
        {
            mini.push(val);
        }

        else
        mini.push(min(mini.top(), val));
    }


    void pop()
    {
        st.pop();
        mini.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return mini.top();
    }
};


int main()
{
    MinStack s;// = new MinStack();
    s.push(10);
    s.push(50);
    s.push(5);
    s.push(20);
    s.push(30);
    
    cout << "Output:" << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.getMin();
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
