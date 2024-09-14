// Palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*
class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}
};
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int size = s.length();
        string str = "";

        int c;
        for (int i = 0; i < size; i++)
        {
            c = s[i];
            if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
                str += c;

        }

        transform(str.begin(), str.end(), str.begin(), ::tolower);
        int len = str.length();

        if (len < 2)
            return true;

        bool f = true;
        for (int i = 0; i < len / 2; i++)
        {
            if (str[i] != str[len - 1 - i])
            f = false;
        }
        return f;
    }
};


int main()
{
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    cout<<s.isPalindrome(str);

    
}

