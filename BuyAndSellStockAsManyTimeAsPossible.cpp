#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size < 3)
        {
            if (size < 2 || prices[0] >= prices[1])
                return 0;
            else
                return prices[1] - prices[0];
        }

        int buy = 0;
        int sell = 0;
        int profit = 0;
        for (int i = 1; i < size; i++)
        {
            if (prices[i] >= prices[i - 1])
                sell++;
            else
            {
                profit += prices[sell] - prices[buy];
                buy = sell = i;
            }
        }

        profit += prices[sell] - prices[buy];
        return profit;

    }
};

int main()
{
    Solution S;
    vector <int> prices{ 7,1,5,3,6,4 };
    int ans = S.maxProfit(prices);
    cout << ans;
    return 0;
}