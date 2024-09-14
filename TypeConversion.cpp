// atoi: converts string to integer. It converts the input digits (that are stored as characthers) into integers. 
//except digits if any other character is found the function terminates and returns the value of n.

#include <stdio.h>
int atoi(const char s[]) //I used s[] instead of *s
{
    int i, n;
        //char n, k;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    {
       // k = 10 * n;
        n = 10 * n + (s[i] - '0'); //10*n is decimal multiplication required to increase count from 10th to 100th and so forth
    }
        
    return n;
}

void itoa(int* num, char* x)
{
    int i;
    //char s[10];
    for (i = 0; (num[i] >= 0 && num[i] <= 9) && num[i]!=NULL; ++i)
        *(x+i) = num[i];
    *(x + i) = '\0';
    
}

int main()
{
    int i;
    const char p[] = "17446";//or const char *p = "17446" ;
    int a[10] = { 1,2,3 };
    const char* s = p;
    char x[10];
    printf("%p\n", p);
    printf("%p\n", s);
    printf("%p\n", &s);
    printf("%s\n", s);
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("atoi value of s: %d", atoi(s));
    itoa(a, x);
    printf("\n");
    // printf("\nitoa value of a: %s", x);//not working check book or Internet
    for (i = 0; i < sizeof(x) / sizeof(int); ++i)
        printf("%c", *(x+i));
   
   return 0;
}



