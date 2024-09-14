// InfixToPostFix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

int preced(char c) {//this returns the precedence of the operator
    if (c == '^')
        return 3;
    else if (c == '/' || c== '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else 
        return -1;
}

string inFixToPostFix(string s) //this is the function that does the infix to postfix
{
    stack <char> st;
    st.push('E');
    char c;
    string result;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')//this is to check for white space
            continue;

        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            result += s[i];
        else if (s[i] == '(')
            st.push(s[i]);

        else if (s[i] == ')') 
        {
            while (st.top() != 'E' && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        //else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='^')
        else
        {
            c = s[i];
            if (st.top() == 'E')
                st.push(c);
            else
            {
                while ((preced(st.top()) >= preced(c)) && st.top() != 'E')
                {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
    }

    if (st.top() != 'E')
    {
        while (st.top() != 'E')
        {
            result += st.top();
            st.pop();
        }
    }
    return result;
}


int main()
{
    string s = "(A+B)*(C*D-E)*F/G";
    cout << "Before the fix: ";
        cout << s;
        cout << endl<<"After the fix: ";
    cout<<inFixToPostFix(s);
    //cout << s;
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
