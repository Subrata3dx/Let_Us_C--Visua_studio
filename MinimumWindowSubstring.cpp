// MinimumWindowSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(128, 0);
        for (auto c : t) v[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()) 
        {
            char c = s[end]; 
            end++;
            if (v[c] > 0)
            {
                counter--;                
            }
            v[c]--;
            
            
            while (counter == 0) 
            { 
                if (end - begin < d) //d updates whenever end - begin is less than d
                {
                    head = begin;
                    d = end - begin;
                }

                char x = s[begin];
                begin++;
                if (v[x] == 0) //true for the character(letter) that is available in string t
                {
                    counter++;                   
                }
                v[x]++; //again making the vector v as it was before starting the outer while loop, except for the last character of string s
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d); // d is not index, it is number of digits 
    }
};

int main()
{
    Solution so;
    string s = "CDEAB";
    string t = "AB";
    cout << so.minWindow(s, t); 
    return 0;
}

