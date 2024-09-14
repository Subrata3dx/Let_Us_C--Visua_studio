// SimpleMatrixUsingClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Matrix {
private:
    int Mat1[2][2], Mat2[2][2], Mat3[2][2];
public:
    void FillMat(int x)
    {
        int Mat[2][2];
        int k;
        if (x == 1)
        {

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++) {
                    cout << "For Mat1[" << i << "][" << j << "] enter a value: ";
                    cin >> Mat1[i][j];
                }
        }
        
        if(x==2)
        {

             for (int i = 0; i < 2; i++)
                 for (int j = 0; j < 2; j++) {
                     cout << "For Mat2[" << i << "][" << j << "] enter a value: ";
                     cin >> Mat2[i][j];
                 }
        }

    }

    void DisplayMat(int x)
    {
        
        if (x == 1)
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cout << Mat1[i][j] << "\t";
                }
                cout << endl;
            }
        }

        if (x == 2)
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cout << Mat2[i][j] << "\t";
                }
                cout << endl;
            }
        }
    }


    void AddMat()
    {
        cout << "After addition of two matrices: " << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
              // cout<<Mat3[i][j] = Mat1[i][j] + Mat2[i][j]<<"\t"; //it does not work may be cascading is not possible with assingment and other normal output
                Mat3[i][j] = Mat1[i][j] + Mat2[i][j];
               cout << Mat3[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix M1;
    M1.FillMat(1);
    cout << endl;
    M1.FillMat(2);
    cout << endl;
    M1.AddMat();
    //M1.DisplayMat(1);

    return 0;

}


