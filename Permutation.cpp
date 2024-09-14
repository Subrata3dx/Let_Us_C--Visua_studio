// Permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> result;

    // Backtracking
    void permutation(vector<int>& nums, int i, int n)
    {
        if (i == n)
        {
            result.push_back(nums);
            return;
        }

        for (int j = i; j <= n; j++)
        {
            swap(nums[i], nums[j]);
            permutation(nums, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        permutation(nums, 0, nums.size() - 1);

        return result;
    }
};


int main()
{
    vector<int> x{ 1, 2, 3 };
    Solution so;
    vector<vector<int>> v;
    v = so.permute(x);
    for (auto y : v)
    {
        for (auto z : y)
        {
            cout << z<<", ";
        }
        cout<<endl;
    }
   
    return 0;


   
}


