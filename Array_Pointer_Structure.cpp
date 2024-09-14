
//Passing array of structures as argument
#include<stdio.h>
struct student
{
    char name[20];
    int rollNo;
    int mark;
};
void dec_mark(struct student stuarr[]);
void  display(struct student); //void  display(struct student *);  //Try by removing the comments you will get same results: One is call by value and other is call by address
int main()
{
    
    int i;
    struct student stuarr[3] = {
        {"Vishnu", 2, 90}, {"Krishna", 1, 100}, {"Madhav", 3, 110}
    };
    struct student stu;
    
    dec_mark(stuarr);
    for (i = 0; i < 3; i++)
        display(stuarr[i]); //display(& stuarr[i]); 
}

void dec_mark(struct student stuarr[])
{
    int i;
    for (i = 0; i < 3; i++)
        stuarr[i].mark = stuarr[i].mark - 10;
    
}

void display(struct student stu)
{
    printf("Name of student: %s", stu.name); //printf("\nName of student: %s", stu->name);
    printf("\nRoll number of student: %d", stu.rollNo); //printf("\nRoll number of student: %d", stu->rollNo);
    printf("\nMark of student: %d", stu.mark); //printf("\nMark of student: %d", stu->mark);
    printf("\n");
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
