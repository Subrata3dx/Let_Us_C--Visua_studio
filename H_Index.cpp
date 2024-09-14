
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {

        if ((citations.size() < 2) && (citations[0] > 0))
            return 1;

        int occurance, value = 0;
        for (int i = 0; i < citations.size(); i++)

        {
            occurance = 0;
            for (int j = 0; j < citations.size(); j++)
            {
                if (citations[j] >= citations[i] && citations[i] != 0)
                    occurance++;
            }

            if ((occurance >= citations[i]) && (value < citations[i]))
            {
                value = citations[i];
            }
            else if (occurance > value && value != 0 && occurance <= citations.size())
                value = occurance;
                
            
            
            else
            {
                if (occurance <= citations.size() && value == 0)

                    value = occurance;
            }
            

        }

        return value;
    }
};

int main()
{
    Solution so;
    vector <int> citations{ 0, 2, 1 };
    cout<<so.hIndex(citations);
    return 0;
}

