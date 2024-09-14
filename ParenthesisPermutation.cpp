// ParenthesisPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> vs;
    vector<string> generateParenthesis(int n) {

        string temp = "";
        int count = -1;
        makePairs(0, n, count, temp);
        return vs;
    }

    void makePairs(int idx, int n, int& count, string& temp)
    {
        count++;
        if (count == n)
        {
            return;
        }
        

        if (count == n * 2)
        {
            vs.push_back(temp);
            temp.clear();
            count == 0;
            return;
        }

        for (int i = idx; i < n; i++)
        {
            temp.push_back('(');
            makePairs(idx + 1, n, count, temp);
            temp.push_back(')');
            makePairs(idx + 1, n, count, temp);
        }


    }
};

int main()
{
    Solution so;
    vector<string> s;
    s = so.generateParenthesis(2);
    return 0;
}


