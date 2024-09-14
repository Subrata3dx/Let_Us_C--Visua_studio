#include<vector>
#include <iostream>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return false;
        if (size == 1 || (nums[0] >= size))
            return true;

        bool stat = false;
        int i = 0;
        while(i < size)
        {
            int j = nums[i];
            if (j >= size)
                return true;

            if (nums[j] == 0)
            {
                while (j >= 1)
                {
                    i = i + --j;
                }
                
                
            }

            else
                i = i + j;

            if (i>= size)
            {
                stat = true;
                return stat;
            }


        }
        return stat;
    }
};

int main()
{
    Solution s;
    vector <int> nums = { 3,2,1,0,4 };
    bool ans = s.canJump(nums);
    cout << ans;
    return 0;
}

