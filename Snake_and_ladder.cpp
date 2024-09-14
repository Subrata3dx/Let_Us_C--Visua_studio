// Snake_and_ladder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

#include<queue>
#include <numeric>

using namespace std;




class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), lbl = 1;
        vector<pair<int, int>> cells(n * n + 1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0); //it is not itoa function which is used for converting integer to alpha. The iota() function in C++ is used to assign consecutive increasing values to elements in a range defined by iterators.
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[lbl++] = { row, column };
            }
            reverse(columns.begin(), columns.end()); //reverses the elements of columns that is: 5,4,3,2,1,0
        }
        vector<int> dist(n * n + 1, -1); //assigns all the elements with -1
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) 
        {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                int row = cells[next].first;
                int column = cells[next].second;

                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) 
                {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n * n];
    }
};

int main()
{
    
    Solution so;
    vector<vector<int>> v = { {-1, -1, -1, -1, -1, -1} ,{-1, -1, -1, -1, -1, -1},{-1, -1, -1, -1, -1, -1},{-1, 35, -1, -1, 13, -1},{-1, -1, -1, -1, -1, -1},{-1, 15, -1, -1, -1, -1} };
    cout<<so.snakesAndLadders(v);
    return 0;
}
