// MatricsAddition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    #define MatRow 2
    #define MatCol 2
    int Mat1[MatRow][MatCol], Mat2[MatRow][MatCol], Mat3[MatRow][MatCol];
    cout << "The matrics is of "<<MatRow<<"X"<< MatCol<< endl;
    for (int i = 0; i < MatRow; i++)
    {
        for (int j = 0; j < MatCol; j++)
        {
            cout << "Enter value for Mat1["<< i<<"]["<<j<<"]" << endl;
            cin >> Mat1[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < MatRow; i++)
    {
        for (int j = 0; j < MatCol; j++)
        {
            cout << "Enter value for Mat2[" << i << "][" << j << "]" << endl;
            cin >> Mat2[i][j];
        }
    }

    for (int i = 0; i < MatRow; i++)
    {
        for (int j = 0; j < MatCol; j++)
        {
            Mat3[i][j] = Mat1[i][j] + Mat2[i][j];

        }
    }
    cout << endl;
    cout << "Output after addition of two matrices is :" << endl;
    
    for (int i = 0; i < MatRow; i++)
    {
        for (int j = 0; j < MatCol; j++)
        {
            
            cout << Mat3[i][j] << '\t';
            
        }
        cout << endl;
    }
    return 0;
}

