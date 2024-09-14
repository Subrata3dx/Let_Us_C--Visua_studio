// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct doubleList {
    int info;
    struct doubleList* prev;
    struct doubleList* next;
};

struct doubleList* createList() {
    struct doubleList* node = (struct doubleList*)malloc(sizeof(struct doubleList));
    node->prev = NULL;
    node->next = NULL;
    node->info = NULL;
    return node;
}
void insertData(struct doubleList* ref, int data) {
    struct doubleList* temp, *current;
    temp = ref;
    if (temp == NULL) {
        cout << "List is empty" << endl;
        return;
    }
   
    if (temp != NULL && temp->next == NULL && temp->prev == NULL && temp->info == 0) {
        temp->info = data;
        return;
    }
        
    else {
        while (temp->next != NULL)
            temp = temp->next;

        current = createList();
        current->info = data;
        temp->next = current;
        current->prev = temp;
    }
        return;
}


void printList(struct doubleList* head)
{
    struct doubleList* temp;
    temp = head;
    if (temp == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    else {
        while (temp != NULL)
        {
            cout << temp->info<<endl;
            temp = temp->next;

        }
    }
    return;
}

int main()
{
    
    struct doubleList* head = NULL;
    
    head = createList();
    
    insertData(head, 111);
    insertData(head, 222);
    insertData(head, 333);
    insertData(head, 444);
    printList(head);
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
