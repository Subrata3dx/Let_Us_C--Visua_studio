// Word_break_DP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = true;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if (dp[j] && set.count(sub)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};



int main()
{
    string s = "leetcode";
    vector<string>wordDict{ "leet", "code", "re"};
    Solution so;
   cout<< so.wordBreak(s, wordDict);

}


