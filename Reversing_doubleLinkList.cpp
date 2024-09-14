// Reversing_doubleLinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};


node* reverseList(node* head)
{
    
    
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return head;
    }

    if (head->next ==NULL)
        return head;

    node* p1, * p2;
    p1 = head;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;

    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    head = p1;
    return head;  

}


node* add(node* head, int val)
{
    node* p, * t;
    p = head;

    if (head == NULL) //when no node in the list
    {
        t = new node();
        t->data = val;
        t->next = NULL;
        t->prev = NULL;
        p = t;
        return p;
    }


    if (p->next == NULL) //when only one node in the list
    {
        t = new node();
        t->data = val;
        t->next = NULL;
        t->prev = p;
        p->next = t;
        return head;

    }


    while (p->next != NULL) //when more than one nodes in the list
    {
        p = p->next;
    }

    t = new node();
    t->data = val;
    t->next = NULL;
    t->prev = p;
    p->next = t;
    
    return head;
}

void printList(node* head)
{

    if (head == NULL)
        cout << "\nList is empty.\n";

    else if(head!=NULL)
    {
        if(head->next == NULL)
            cout << head->data << "\t";
        else
        {
            node* t;
            t = head;
            while (t->next!=NULL)
            {
                cout << t->data << "\t";
                t = t->next;
            }
            cout << t->data << "\t";
        }
    }
    
    cout << endl;

}

void printRev(node* head)
{
    node* t;
    t = head;
    while (t->next!=NULL)
    {
        t = t->next;
    }

    while (t!= NULL)
    {
        cout <<t->data << "\t";
        t= t->prev;
    }
    cout << endl;
}

int main()
{
    node* p;
    node *head = NULL;
    int data, input;
      
    
    while (true)
    {
       
        cout << "To add data in the list, enter 1." << endl;
        cout << "To reverse the list, enter 2." << endl;
        cout << "To quit the program, enter 3." << endl;
        cout << "To pint the list, enter 4." << endl;
        cout << "To pint the list in reverse order, enter 5." << endl;
        cout << "Enter your choice:" << endl;
        cin >> data;


        switch (data)
        {
        case 1:
        {

            cout << "Enter input to add to the list : " << endl;
            cin >> input;
            head = add(head, input);
            break;
        }
        break;
        case 2:
        {
            head = reverseList(head);
            break;
        }
        break;

        case 3:
        return 0;        
        break;

        case 4:
            printList(head);
            break;

        case 5:
            printRev(head);
            break;

        default:
            cout << "Invalid choice.";
            break;

        }
    }
    
    return 0;
}



