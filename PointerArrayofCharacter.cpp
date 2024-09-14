#include <stdio.h>
#include "header.h"
#include "read_value.h"
#pragma warning(disable : 4996)

int main()

{
    int loanAmt, year;
    printf("Enter the amount you want to take as loan and for how many years: ");
    scanf("%d %d", &loanAmt, &year);
    printf("\nAfter %d year(s) you will be paying total: ", year);
    printf("%f", amount(loanAmt, year));
    read();
 
    return 0;
}
