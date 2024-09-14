// printingNumbersOfDiffrentTypesOfCharacters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

#pragma warning(disable : 4996)

int main()
{
    int c, i, nwhite, nother, atIndex;
    int ndigit[10];
    nwhite = nother = 0;
    FILE* fptr = fopen("C:\\Users\\Subrata.Shil\\Desktop\\LetUsC++\\CfileOpen\\Test.txt", "r");
    if (fptr == NULL)
        printf("No such file is found.\n");
    else
    {
        for (i = 0; i < 10; i++)
            ndigit[i] = 0;
        while ((c = fgetc(fptr)) != EOF)
            if (c >= '0' && c <= '9')
            {
                atIndex = c - '0'; //just to check what values it gets for array index 
                ++ndigit[c - '0'];
            }
            else if (c == '\t' || c == '\n' || c == ' ')
                ++nwhite;
            else
                ++nother;
        
        printf("ASCI value of 0 = %d\n", '0');
        printf("digits = ");
        for (i = 0; i < 10; i++)
            printf("%d ", ndigit[i]);
        printf(", White space = %d, other = %d\n", nwhite, nother);
    }
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
