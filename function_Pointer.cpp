// function_Pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//using namespace std;


//int (*funcptr)(int, int); // this is the declaration of function pointer like, int *ptr. (* name of the pointer) is necessary 
//because, otherwise it will be the declaraion of a function that returns a integer pointer and takes two integer values
//funcptr is the name of the pointer int is the return value (int, int) is the aguments that the function takes
//This means, we can assign this funcptr to a function which takes two int values as arguments and returns an int value
int add(int a, int b)
{
    return a + b;
}

int (*funcPtr2)(int love);

int Prayas(int t)
{
    return 2;
}

int kisna(int love)
{
    funcPtr2 = Prayas; //assingning function pointer with the address of a function
    int rad = 2 * funcPtr2(love); //calling the function with function pointer and then multiplying it with an integer constant 2.
    return rad;
}


int main()
{
    int(*funcptr)(int, int) = add;
    int sum, mul;
   // funcptr = &add; //funcptr = add;
    sum = funcptr(3, 3);
    mul = kisna(2);
    std::cout << "Value from add function: "<<mul << std::endl;
    std::cout << "Value from kisna function: "<<sum<<std::endl;
}
