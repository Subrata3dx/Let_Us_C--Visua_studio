// MaxLineAndLength.cpp : This file contains the 'main' function. Program execution begins and ends there.
// we are using external variables here

#include <stdio.h>
#pragma warning(disable : 4996)


#define MAXIMUM 1000
 int max, c;
 char arr[MAXIMUM], longest[MAXIMUM], t;
 FILE* fptr = fopen("C:\\Users\\Subrata.Shil\\Desktop\\LetUsC++\\CfileOpen\\Test.txt", "r");
//int maxline(void);
void copy(void);

int main()
{
    int len, i, c;
    extern int max;
    extern char longest[];
    max = len = 0;
    do 
    {
        for (i = 0; i < MAXIMUM - 1 && (c = fgetc(fptr)) != EOF && c != '\n'; ++i)
            arr[i] = c;

        if (c == '\n')
        {
            arr[i] = c;
            ++i;
        }

        
        arr[i] = '\0';// to insert a NULL character at the end of the array

        if(i>0)
        max = i;

        if (max > len)
        {
            len = max;
            copy();
        }
    } while (c != EOF);
        
           
      
    if (max > 0)
    {
        printf("Max line's length = %d\n", max);
        printf("Max line is: %s\n", longest);
    }
    return 0;
}

void copy()
{
    int i=0;
    while ((longest[i] = arr[i]) != '\0') // we can also write while ((t = (longest[i] = arr[i])) != '\0') for better understanding. This means while copying there is use of a temporary variable and which is later compared with \0
    ++i;
}

/*int maxline()
{
    int i, c;
    extern char line[];

   
    if (fptr == NULL)
    {
        perror("Pointer error");
        return i = 0;
    }
   
}
*/

