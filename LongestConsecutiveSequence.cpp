#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int size = nums.size();
        if (size < 2)
            return size;
        sort(nums.begin(), nums.end());
        int mx = 1;
        int count = 1;
        for (int i = 1; i < size; i++)
        {

            while (i < size && nums[i] == nums[i - 1] + 1 || i < size && nums[i] == nums[i - 1])
            {
                if (nums[i] != nums[i - 1])
                    count++;
                i++;
            }

            mx = max(mx, count);
            count = 1;

        }

        return mx;
    }
};

int main()
{
    vector <int> nums{ 0,-1 };
    Solution so;
    cout << so.longestConsecutive(nums);
    return 0;
}
