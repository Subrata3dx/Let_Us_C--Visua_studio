#include<iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j=0,  t=0;
        int nums3[m+n];
        while(i<m && j<n)
        {
            if(nums1[i]==nums2[j])
            {
            nums3[t++]=nums1[i++];
            nums3[t++]=nums2[j++];
            }
            else
            {
                nums1[i]<nums2[j] ? nums3[t++]=nums1[i++] : nums3[t++]=nums2[j++];
            }

        }

        if(i==m)
        {
            while(j<n)
            {
                nums3[t++]=nums2[j++];
            }
        }
        if(j==n)
        {
            while(i<m)
            nums3[t++]=nums1[i++];
        }
        
        for(i=0;i<m+n;i++)
        {
            nums1[i]=nums3[i];
        }

       
    }
};

int main()
{
	Solution s;
	vector <int> nums1[1, 2, 3, 4];
	vector <int> nums2[2 , 3, 7];
	
	s.merge(nums1, 4, nums2, 3);
	for(int i =0; i<nums1.size(); i++)
		cout<<nums1[i]<<cout<<"\t";
	return 0;
}