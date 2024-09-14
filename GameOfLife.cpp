#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int row = board.size();
        int col = board[0].size();
        vector<int> v;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                store(board, i, j, v);
            }
        }

        int t = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                board[i][j] = v[t++];
            }
        }

    }

    void  store(vector<vector<int>>& board, int x, int y, vector<int>& v)
    {
        int row = board.size();
        int col = board[0].size();
        int valx = board[x][y];

        int i = x, j = y;
        int val = 100, one = 0, zero = 0;

        i = x-1; j = y-1;
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            val = board[i][j];
            if (val == 1)
                one++;
            else
                zero++;
        }


        j = y;
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            val = board[i][j];
            if (val == 1)
                one++;
            else
                zero++;
        }

        i; j++;
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            val = board[i][j];
            if (val == 1)
                one++;
            else
                zero++;
        }

        i++; j = y - 1;
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            val = board[i][j];
            if (val == 1)
                one++;
            else
                zero++;
        }

        j = y + 1;
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            val = board[i][j];
            if (val == 1)
                one++;
            else
                zero++;
        }

        i++; j = y - 1;
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            val = board[i][j];
            if (val == 1)
                one++;
            else
                zero++;
        }

        j++;
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            val = board[i][j];
            if (val == 1)
                one++;
            else
                zero++;
        }

        j++;
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            val = board[i][j];
            if (val == 1)
                one++;
            else
                zero++;
        }


        if (valx == 1 && one < 2)
            v.push_back(0);

        else if ((one == 3 || one == 2) && valx == 1)
            v.push_back(1);

        else if (one > 3 && valx == 1)
            v.push_back(0);

        else if (one == 3 && valx == 0)
            v.push_back(1);
        else
            v.push_back(valx);
    }

};

void print(vector < vector<int>> vec)
{
    int row = vec.size();
    int col = vec[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << vec[i][j] << " ";

        }
        cout << endl;
    }
};

int main()
{
    vector<vector<int>> vec = {{1, 1}, { 1, 0}};
    Solution so;
    print(vec);
    so.gameOfLife(vec);
    cout << endl;
    print(vec);

}