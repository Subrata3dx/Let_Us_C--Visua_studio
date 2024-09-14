// LetterCombinationsofaPhoneNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
/*queue<char>q;
        map<int, queue<char>>m;
       char aplha = 97;
        for(int i = 2; i<9;i++)
        {
           if(i==7||i==9)
           {
                for(int j = 0; j<4;j++)
                {
                    m[i][j]=aplha++;
                }
           }
            
            for(int j = 0; j<3;j++)
            {
                m[i][j]=aplha++;
            }
        }
        
 */

/*
class Solution {
private:
    void letterCombinations(string digits, vector<string>& output, string& temp, vector<string>& pad, int index) {
        if (index == digits.size()) {
            output.push_back(temp);
            return;
        }
        string value = pad[digits[index] - '0'];
        for (int i = 0; i < value.size(); i++) {
            temp.push_back(value[i]);
            letterCombinations(digits, output, temp, pad, index + 1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> pad = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> output;
        string temp;
        letterCombinations(digits, output, temp, pad, 0);
        return output;
    }
};
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> pad = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> output;
        output.push_back("");
        int a = 0;
        for (auto key : digits) {
            vector<string> temp;
            for (auto candidate : pad[key - '0']) 
            {
                a++;
                for (auto c : output) 
                {
                    temp.push_back(c + candidate);
                }
            }
            output.clear();
            output = temp;
        }
        return output;
    }
};

int main()
{
    string v = "23";
    Solution so;
    so.letterCombinations(v);
    return 0;
}
