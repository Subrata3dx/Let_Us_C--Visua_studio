// ListOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program lists the operations 

#include <stdio.h>
#include<stdlib.h>


struct node {
    int value;
    struct node* link;

};


struct node* start = NULL;
struct node* createList();
int getData();
struct node* selectOptions(struct node* start);
void printList(struct node* start);
struct node* addAtbeg(struct node* start, int data);
struct node* addAtEnd(struct node* start, int data);
struct node* addAtLoc(struct node* start, int data, int loc);
struct node* addAfter(struct node* start, int item, int data);
struct node* addBefore(struct node* start, int item, int data);

struct node* DeleteAtLoc(struct node* start, int item);
struct node* DeleteAfter(struct node* start, int item);
struct node* DeleteBefore(struct node* start, int item);
struct node* DeleteAtBeg(struct node* start);
struct node* DeleteAtEnd(struct node* start);
struct node* reverseList(struct node* start);

int main()
{
  

    //calls
    //start = createList();
    //printList(start);
    start = selectOptions(start);
    //start = addAtEnd(start, 100);
    //printList(start);
    return 0;
}



 

//Create a list
struct node* createList()
{
    int n, i, data;
    struct node *p, *tmp;
    p = NULL;

    printf("Enter the number of nodes: ");
    scanf_s("%d", & n);
    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf_s("%d", &data);
        p = addAtEnd(p, data);

    }
    return p;
}
 
//Add operations:

//Add a node at the end
struct node* addAtEnd(struct node* start, int data)
{
    struct node* p, * tmp;
    p = start;
    if (p == NULL)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->value = data;
        p->link = NULL;
        return p;
    }
    while (p->link != NULL)
    {
        p = p->link;

    }
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->value = data;
    tmp->link = NULL;
    p->link = tmp;
    return start;

}

//Add a node at the begining

struct node* addAtbeg(struct node* start, int data)
{
    struct node* p, * tmp;
    p = start;
    if (p == NULL)
    {
        //printf("No list exists to add the item. Create the list first.");
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->value = data;
        tmp->link = NULL;
        return tmp;
    }
    if (p != NULL)
    {
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->value = data;
        tmp->link = p;
        return tmp;
    }
}

//Add a node at any location
struct node* addAtLoc(struct node* start, int loc, int data) 
{
    int i=0, j=1;
    struct node* p, *tmp;
    p = start;
   
    if (loc==1)
    {
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->value = data;
        tmp->link = p;        
        return tmp;
    }
    
    else
    {
        while (p != NULL)
        {
            i += 1;
            p = p->link;
        }
        if (loc > i)
        {
            printf("\nThe list is smaller than the location.\n");
            return start;
        }
        else
        {
            p = start;
            j += 1;
            while (j < loc)
            {
                p = p->link;
                j += 1;
            }
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp->value = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
    }


}

//Adding before a specific node
struct node* addBefore(struct node* start, int item, int data)
{
    struct node* p, *tmp;
    p  = start;
    if (p == NULL) 
    {
    printf("\nList is empty.\n");
    return start;
    }

    if (p->value == item)
    {
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->value = data;
        tmp->link = p;
        
        return tmp;
    }
    while (p->link != NULL)
    {
        if (p->link->value == item)
        {
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp->value = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }

       
        p = p->link;
    }
    printf("\nItem not found.\n");
    return start;
}

//Adding after a specific node
struct node* addAfter(struct node* start, int item, int data)
{
    struct node* p, *tmp;
    p = start;
    if (p == NULL)
    {
        printf("\nEmpty list.\n");
        return start;
    }

    while (p!= NULL)
    {
        if (p->value == item)
        {
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp->value = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;

    }
    printf("\nItem not found.\n");
    return start;

}

//Delete operations:

//Delete at any location
struct node* DeleteAtLoc(struct node* start, int loc)
{
    struct node* p, *tmp;
    int count = 0, j = 1;

    p = start;
    
    while(p!=NULL)
    {
        count+=1;
        p = p->link;
    }
    if (loc > count)
    {
        printf("\nLocation is greater than the list.\n");
        return start;

    }

    p = start;
    if (loc == 0)
    {
        printf("\nLocation does not exist.\n");
        return start;
    }
    if (loc==1)
    {
        p = p->link;        
        return p;
    }

    else
    {
        j += 1;
        while (j < loc)
        {
            p = p->link;
            j++;
        }
        tmp = p->link;
        p->link = tmp->link;
        return start;
    }

    
}

//Delete before
struct node* DeleteBefore(struct node* start, int item)
{
    struct node* p, * tmp, * q;
    p = start;
    if (p->value == item)
    {
        printf("\nCant delete a node which supposed to exist before the start node.\n");
        return start;
    }
    if (p->link->value == item)
    {
        start = p->link;
        return start;
    }


    while (p != NULL)
    {
        q = p;
        tmp = p->link;

        if (tmp->link == NULL)
        {
            printf("\nThe item does not exist.\n");
            return start;
        }

        if(tmp->link->value == item)
        {
            q->link = tmp->link;
            return start;
        }
        p = p->link;

    }
    return start;
}
        
    

//Delete After
struct node* DeleteAfter(struct node* start, int item)
{
    struct node* p, * tmp, * q;
    p = start;
    
   

    while (p != NULL)
    {
        if ((p->value == item) && (p->link == NULL))
        {
            printf("\nCant delete a node which supposed to exist after the end of a list.\n");
            return start;
        }

        if ((p->value == item) && (p->link != NULL))
        {
            tmp = p->link;            
            p->link = tmp->link;
            return start;
        }
        
        p = p->link;

     }
    printf("\nThe item does not exist.\n");
    return start;
}


// Delete at Beginning

struct node* DeleteAtBeg(struct node* start)
{
    return start->link;
}

//Delete at end
struct node* DeleteAtEnd(struct node* start)
{
    struct node* p, *q;
    p = q= start;
    if (p->link == NULL)
        return  NULL;

    while (p->link != NULL)
    {
        q=p;
        p = p->link;
    }
    q->link = NULL;
    return start;
}

//reverse the list

struct node* reverseList(struct node* start)
{
    struct node* p, * q, * r;
    p = q = r = start;
    if (p -> link == NULL)
        return p;

    p = p->link;
    if (p->link == NULL)
    {
        p->link = q;
        q->link = NULL;
        return p;
    }
    while (p->link != NULL)
    {
       
        q = r;
        r = p;
        p = p->link;
        r->link=q;
        start->link = NULL;
        if (p->link == NULL)
        {
            p->link = r;
            
            return p;
        }
    } 
}

void printList(struct node* start)
{
    struct node* p;
    p = start;
    
    if (p == NULL)
        printf("\nList is empty\n.");

    while (p!= NULL)
    {
        printf("%d \t", p->value);
        p =p->link;
    }
    return;
}



int getData()
{
    int data;
    printf("Enter the value: ");
    scanf_s("%d", &data);
    return data;

}

struct node* selectOptions(struct node* start)
{
    int option, data, item;
    while (true)
    {
        printf("\nSelect the option you want to perform:\n");
        printf("To print the list enter: 0");
        printf("\nTo add a node at the beginning of the list enter: 1");
        printf("\nTo add a node at the end of the list enter: 2");
        printf("\nTo add a node before an item in the list enter: 3");
        printf("\nTo add a node after an item in the list enter: 4");
        printf("\nTo add a node at any position in the list enter: 5");
        printf("\nTo delete a node before an item in the list enter: 6");
        printf("\nTo delete a node after an item in the list enter: 7");
        printf("\nTo delete the beginning node in the list enter: 8");
        printf("\nTo delete the end node in the list enter: 9");
        printf("\nTo delete a node at any position in the list enter: 10");
        printf("\nTo reverse the list enter: 11");
        printf("\nTo quit enter: 12\n");
        scanf_s("%d", &option);
        switch (option)
        {
        case 0:
        {
            printList(start);            
            break;
        }
        case 1:
        {
            data = getData();
            start = addAtbeg(start, data);
            break;
        }
        case 2:
        {
            data = getData();
            start = addAtEnd(start, data);
            break;
        }
        case 3:
        {
            if (start == NULL)
            {
                printf("\nList is empty.\n");
                
            }
            else 
            {
                data = getData();
                printf("Enter the item: ");
                scanf_s("%d", &item);
                start = addBefore(start, item, data);
            }
            break;

        }

        case 4:
        {
            if (start == NULL)
            {
                printf("\nList is empty.\n");
                
            }
            else
            {
                data = getData();
                printf("Enter the item: ");
                scanf_s("%d", &item);
                start = addAfter(start, item, data);
            }
            break;

        }

        case 5:
        {
            if (start == NULL)
            {
                printf("\nLink does not exist.\n");
            }
            else
            {
                data = getData();
                printf("Enter the location: ");
                scanf_s("%d", &item);
                start = addAtLoc(start, item, data);
            }
            break;

        }

        case 6:
        {
            if (start == NULL)
            {
                printf("\nLink does not exist.\n");
            }
            
            else
            {
               
                printf("Enter the item before which you want to delete a node: ");
                scanf_s("%d", &item);
                start = DeleteBefore(start, item);
            }
            break;
        }

        case 7:
        {
            if (start == NULL)
            {
                printf("\nLink does not exist.\n");
            }

            else
            {

                printf("Enter the item after which you want to delete a node: ");
                scanf_s("%d", &item);
                start = DeleteAfter(start, item);
            }
            break;
        }

        case 8:
        {
            if (start == NULL)
            {
                printf("\nLink does not exist.\n");
            }
            else                    
                start = DeleteAtBeg(start);
           
            break;
        }

        case 9:
        {
            if (start == NULL)
            {
                printf("\nLink does not exist.\n");
            }
            else
                start = DeleteAtEnd(start);

            break;
        }

        case 10:
        {
            if (start == NULL)
            {
                printf("\nLink does not exist.\n");
            }
            else
            {
                
                printf("Enter the location: ");
                scanf_s("%d", &item);
                start = DeleteAtLoc(start, item);
            }
            break;
        }

        case 11:
        {
            if (start == NULL)
            {
                printf("\nLink does not exist.\n");
            }
            else
            {

               start = reverseList(start);
            }
            break;
        }
        case 12:
            return start;
            break;

        default:
        {
            printf("\nNot a valid option! Choose a valid option.\n");
            break;

        }


        }


    }
    return start;
}

