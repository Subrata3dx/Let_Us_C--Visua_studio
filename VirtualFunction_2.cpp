// VirtualFunction_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct base
{
protected:
	int a;
public:
	
	 base(int g)
	 {
		 a = g;
	 }

	 virtual void fun1()
	 {
		 cout << "\nFrom base class "<<a<<endl;
	 }
};

struct derived: public base
{
private:
	int b =4;
public:
	
	derived(int j, int k):base(k)
	{
		b = j;
		base::fun1();
		base* p;
		p = this;
		p->fun1();
		
	}

	void fun1()
	{
	//	base* p = this;
		//p->fun1();
		cout << "\nFrom derived class "<<b<<endl;
	}
};

int main()
{
	base b(10);
	derived d(100, 200);
	return 0;

}


