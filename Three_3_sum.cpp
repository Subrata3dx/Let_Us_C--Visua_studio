
#include <iostream>
#include <vector>
using namespace std;

class Solutions
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int s = nums.size();
        int t = 0;
        vector < vector<int>> v;
        
        for (int i = 1; i < s - 1; i++)
        {
            for (int j = 0, k = s - 1; j < s - 1 && k >= 0; k--, j++)
            {
                if (i != j && i != k && j != k)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        v.push_back({ nums[i], nums[j], nums[k] });
                        t++;
                    }
                }
            }
        }
        return v;
    }
};


int main()
{
    vector<int>nums{ -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> vi;
    Solutions so;
    vi = so.threeSum(nums);

    for (auto x : vi)
    {
        for (int i = 0; i < 3; i++)
            cout << x[i] << ", ";
    }
    
    return 0;
}
