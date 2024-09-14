// MatrixArithmetics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class matrix {
private:
    int mat1[3][3];
    int k = 0;
public:
    void setdata() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                mat1[i][j] = ++k;
    }
    void getdata()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << mat1[i][j] << '\t';

            cout << endl;
        }
    }
    int send(int x, int y)
    {

        return mat1[x][y];
    }

    void set(int x, int y, int data)
    {
        mat1[x][y] = data;
    }
    
    matrix operator+(matrix x)
    {
        matrix temp;
         for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            temp.mat1[i][j] = mat1[i][j] + x.mat1[i][j];
        return temp;
    }
};

int main()
{
    matrix a, b, c, d, e, *p;
    //matrix operator+(matrix x, matrix y);
    matrix operator-(matrix x, matrix y);
    matrix operator*(matrix x, matrix y);

    
    p = &a; //assigning a pointer to an object

    a.setdata();
    //p->getdata();
    b.setdata();
    c = a + b;
    d = a - b;
    c.getdata();
    cout << endl;
    d.getdata();
    e = a * b;
    cout << endl;
    e.getdata();
}

/*matrix operator+(matrix x, matrix y) {
    
    matrix temp;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.set(i, j, (x.send(i, j) + y.send(i, j)));
    return temp;
}
*/

matrix operator-(matrix x, matrix y) {

    matrix temp;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.set(i, j, (x.send(i, j) - y.send(i, j)));
    return temp;
}

matrix operator*(matrix x, matrix y)
{
    
    matrix temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp.set(i, j, 0);
            for (int k = 0; k < 3; k++)
                temp.set(i, j, (temp.send(i,j) + x.send(i, k) * y.send(k, j)));
        }
    }
    return temp;
}
