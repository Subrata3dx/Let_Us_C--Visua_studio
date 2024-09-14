#include<string>
#include <iostream>
using namespace std;

class Solution {
public:
    string temp = "";
    void add(string str, int dig)
    {
        while (dig > 0)
        {
            temp = temp + str;
            dig--;
        }
    }

    string intToRoman(int num)
    {
        int tn = num, s = 0;

        while (tn > 0)
        {
            tn = tn / 10;
            s++;

        }

        int k = num, digit;
        while (s > 0)
        {
            if (s > 3)
            {
                digit = k / 1000;
                add("M", digit);
                k = k % 1000;
            }

            else if (s > 2)
            {
                digit = k / 100;
                if (digit < 4)
                    add("C", digit);
                else if (digit == 4)
                    temp = temp + "CD";
                else if (digit == 5)
                    temp = temp + "D";
                else if (digit > 5 && digit < 9)
                {
                    temp = temp + "D";
                    add("C", digit - 5);
                }

                else if (digit == 9)
                    temp = temp + "CM";
                k = k % 100;
            }

            else if (s > 1)
            {
                digit = k / 10;
                if (digit < 4)
                    add("X", digit);
                else if (digit == 4)
                    temp = temp + "XL";
                else if (digit == 5)
                    temp = temp + "L";
                else if (digit > 5 && digit < 9)
                {
                    temp = temp + "L";
                    add("X", digit - 5);
                }
                else if (digit == 9)
                    temp = temp + "XC";

                k = k % 10;
            }

            else if (s == 1)
            {
                
                if (k < 4)
                    add("I", k);
                else if (k == 4)
                    temp = temp + "IV";
                else if (k == 5)
                    temp = temp + "V";
                else if (k > 5 && k < 9)
                {
                    temp = temp + "V";
                    add("I", k-5);
                }
                else if (k == 9)
                    temp = temp + "IX";
            }

            //k = k % 10;
            s--;
        }
        return temp;
    }

};


int main()
{
    int number = 1994;
    Solution so;
    string s = so.intToRoman(number);
    cout << s;
    
}
