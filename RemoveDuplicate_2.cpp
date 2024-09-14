// RemoveDuplicate_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solutions
{
public:
    int removeDuplicate(vector<int>& v)
    {
        int si = v.size();
        /*int j = 2;
        for (int i = 2; i < si; i++)
        {
            int k = v[i];
            if (v[i] != v[i-2])
            {
                v[j] = k;
                j++;
            }
            
        }
        */
        int i = 0;
        for (auto x : v)
        {
            if (i == 0 || i == 1 || v[i - 2] != x)
            {
                v[i] = x;
                i++;
            }
        }

        return i;

        //return j;
    }

    void print(vector<int> &v)
    {
        for (auto x : v)
        {
            cout << x<<" ";
        }
    }
};

int main()
{
    Solutions so;
    vector<int> v = {1,1,1,2,2,3};
    cout << "Before fuction call: ";
    so.print(v);
    
    cout<<endl<<"Element count:"<<so.removeDuplicate(v);

    cout <<endl<< "After fuction call: ";
    so.print(v);
    return 0;
}
