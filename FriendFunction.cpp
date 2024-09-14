// FriendFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Frnd2;// Declaration of class. If we dont do, friend function has no clue of Frnd2 in its parameter list, hence, error will be shown. 
class Frnd1
{
	int age;
	friend int test(Frnd1, Frnd2);
	
public:
	Frnd1()
	{
		age = 89;
	}

	int getAge()
	{
		return age+11;

	}
};

class Frnd2
{
	int pension;

	friend int test(Frnd1, Frnd2);

public:
	Frnd2()
	{
		pension = 10000;
	}

};

int test(Frnd1 a, Frnd2 p)
{
	return p.pension/a.age;
}

int main()
{
	Frnd1 f;
	Frnd2 g;
	std::cout << "Accesing the member value using object: " <<f.getAge();
	std::cout << std::endl;
	std::cout << "Accesing the member values via friend function.";
	std::cout<<"\nPer week saving: "<< test(f, g);
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
