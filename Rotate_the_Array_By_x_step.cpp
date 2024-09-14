#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int t;
        int s = nums.size();
        t = k % nums.size();
        if (s == 1)
            ;
        else
        {
            reverse(nums.begin(), nums.begin() + (s - t));
            reverse(nums.begin() + (s - t), nums.end());
            reverse(nums.begin(), nums.end());
        }
    }


};





// do not use this code, it is just waste of time... 

/*

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size(), t = k;
        
        int mod = t % s;
        int  last = s - 1;


        if (t >= 0 && s > 1)
        {
            int pos = 0;
            int    temp2 = nums[pos], temp1, p, i = 0;
            p = last;

            
            if (s/k==2&& s%k==0)
            {
                while (i < k)
                {

                    temp1 = nums[i];
                    pos = i + mod;
                    if (pos > last)
                        pos = (pos - last) - 1;

                    temp2 = nums[pos];
                    nums[pos] = temp1;
                    nums[i] = temp2;

                    i++;
                }

            }

            else
            {
                while (p >= 0)
                {

                    temp1 = temp2;
                    pos = pos + mod;
                    if (pos > last)
                        pos = (pos - last) - 1;

                    temp2 = nums[pos];
                    nums[pos] = temp1;
                    p--;

                }
            }
        }

    }

};


*/

int main()
{
    Solution s;
    vector <int> nums{ -1,-100,3,99 };
    s.rotate(nums, 2);
    for (auto x : nums)
        cout << x<<"\t";
    return 0;


}


/*
Working, but not good for large input

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size(), t = k;
      int  last = s-1;
      int mod = k%s;

        if (k>=0&&s>1)
        {

        while(mod>0)
        {
            int temp = nums[last];
            int i = 0;
            while(i<last)
            {
            nums[last-i] = nums[last-1-i];
            i++;
            }
            nums[0] = temp;
            mod--;
        }

        }
    }
};
*/