// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;


/*
int i = 10;
int main()
{
	int i = 20;
	cout << i << endl << ::i << endl;
	
	{
		i = 30;
		cout << i << endl << ::i << endl;
		//cout << i << endl << ::i<<endl<<::::i;
	}
}

*/
/*
void main()
{
	int i = 5;
	int& j = i;
	int p = 10;
	j = p;	
	
	cout <<"i = "<< i << endl <<"j= "<< j << endl;
	p = 20;//this is not updated until we reassign p to j
	j = p;
	cout << "i = " << i << endl << "j= " << j;

}
*/


/*
int const I = 10; //const int I or int const I is same for normal variable (it seems).
int main()
{
	 const int I = 20; //allowed, it's like totally a new definition 
	cout << I << endl << ::I<<endl;
	//I = 30;
	cout << &I << endl << &::I;
	return 0;
}
*/

/*

int main()
{
	char  a[5] = {'a', 'b'};
	const char* p ="Bharat";
	const char* q = p;
	cout << p << endl << q<<endl;
	q = a;
	p = "joker";
	cout << p << endl << q;
	a[1] = 'k';
	cout << endl << q;
	return 0;
}

*/



int x = 224;
int main()
{
	const int* sample();	
	const int* p;	
	//*p = 12;	
	p = sample();	
	cout << p;	
	return 0;
}

const int* sample()
{
	return(&x); //the address of x is a const, not because it's declared as const int
}


