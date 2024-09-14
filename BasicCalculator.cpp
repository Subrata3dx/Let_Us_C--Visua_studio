// BasicCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;


class Calculator
{
public:
    int evaluate(string s)
    {
        stack<int>st;
        int sign = 1;
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(ans);
                st.push(sign);
                ans = 0; 
                sign = 1;

            }

            else if (s[i] == '+')
            {
                sign = 1;
            }

            else if (s[i] == '-')
            {
                sign = -1;
            }

            else if (s[i] == ')')
            {
                ans = ans * st.top();
                st.pop();
                ans = ans + st.top();
                st.pop();
            }

            else if(s[i]>='0')
            {
                int num = 0;
                while (i < s.length() && s[i] >= '0' )
                {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                i--;

                ans = ans + (num*sign);
            }
        }

        return ans;
    }
};

int main()
{
    
    string equ = "-(2+3) + (5 - 3)";
    Calculator ca;
    cout<<ca.evaluate(equ);
    return 0;

}

