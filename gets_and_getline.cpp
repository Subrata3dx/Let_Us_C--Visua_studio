// gets_and_getline.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)
int main()
{
    /*
    FILE* fp;
    fp = fopen("C:\\Users\\Subrata.Shil\\Desktop\\LetUsC++\\CfileOpen\\test.txt", "r");
    char str[100], * abc;

    fgets(str, 10, fp);
   // printf("Enter your text:");
    //abc = gets(str); // gets() is of char* gets(char* str) type. It returns a character pointer and takes a character pointer
    
    printf("\nEntered text is:%s", str);
    return 0;
    */


    FILE* fp;
    fp = fopen("C:\\Users\\Subrata.Shil\\Desktop\\LetUsC++\\CfileOpen\\test.txt", "r");
    int bytes_read, size = 10;
    char* string;
    printf("Pleas enter a string: ");
    string = (char*)malloc(size);
    bytes_read = getline(&string, &size, fp);
    if (bytes_read == -1)
        puts("\nError!");
    else
    {
        puts("\nYou entered the following string:");
        puts(string);
        printf("Current size for the string block: %d", bytes_read);

    }

    printf("\n%d", string);
    printf("\n%d", &string);
    return 0;
}
