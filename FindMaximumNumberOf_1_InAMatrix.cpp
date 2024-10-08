// FindMaximumNumberOf_1_InAMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int FindMax1sInARow(int matrix[4][4])
{

    int count = 0;
    int row = 0;
    for (int i = 0; i < 4; i++)
    {
        int maxrow = 0;
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j] == 1)
                maxrow++;
        }

        if (count < maxrow)
        {
            count = maxrow;
            row = i;
        }
    }
    return row;
}
int main()
{
    int matrix[4][4] = { {0,0,1,1}, {1,0,1,1}, {0,1,1,0}, {1, 1, 1, 1} };
    
    cout << "Maxium number of 1s are in row number " << FindMax1sInARow(matrix);
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
