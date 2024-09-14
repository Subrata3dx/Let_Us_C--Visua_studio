// GCD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <conio.h>

int gcd(int a, int b);

int main()
{
    int a, b;
    printf("Enter the value of a:\n");
    scanf_s("%d", &a);
    printf("Enter the value of b:\n");
    scanf_s("%d", &b);
    if (a > b)
        printf("The GCD among a and b is: %d", gcd(a, b));
    else
        printf("The GCD among a and b is: %d", gcd(b, a));
    return 0;
}

int gcd(int a, int b) {
    if ((a % b) == 0)
        return b;
    else
        return gcd(b, a % b);
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
