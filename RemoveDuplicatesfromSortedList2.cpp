
#include <iostream>
using namespace std;


 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
 public:
     ListNode* deleteDuplicates(ListNode* head) {

         if (head == NULL || head->next == NULL)
         {
             return head;
         }

         /* The following code doesnot work few last test cases. It is kind of chipping in code whenever test failed

         bool k;
         ListNode *curr, *futr, *prev;
         ListNode* dummy = new ListNode();
         dummy -> next = head;
         prev = dummy;
         curr = head; futr = curr->next;

         while(futr) //this I could have taken as curr, and change the code as necessary
         {
         if(curr->val==futr->val)
         {
             curr=curr->next;
             futr=futr->next;
             k = true;
             continue;
         }

         else
         {
             if(k==true)
             {
                 ListNode * temp = new ListNode(futr->val);
                 temp->next = futr;
                 curr = curr->next;
                 futr = futr->next;


                  if(futr!=NULL &&  temp->val==futr->val)
                  ;

                  else
                 prev->next=temp->next;
             }
             else
             {
                 futr=futr->next;
                 curr=curr->next;
                 prev = prev->next;
             }
         }


         k=false;
         }

         if(dummy==prev)
         dummy->next=NULL;

         if(k==true)
         prev->next = NULL;

         return dummy->next;
     }
 };*/


         ListNode* dummy = new ListNode(0, head);
         ListNode* prev = dummy;

         while (head != NULL)
         {

             if (head->next != NULL && head->val == head->next->val)
             {

                 while (head->next != NULL && head->val == head->next->val)
                 {
                     head = head->next;
                 }

                 prev->next = head->next;
             }

             else
             {
                 prev = prev->next;
             }

             head = head->next;
         }

         return dummy->next;

     }
 };





void printList(ListNode* h)
{
    while (h)
    {
        cout << h->val << " ";
        h = h->next;
    }
}

int main()
{


   // ListNode* l1 = new ListNode(5);
    //ListNode* l2 = new ListNode(4, l1);
    ListNode* l3 = new ListNode(3);// , l2);
    ListNode* l4 = new ListNode(1, l3);
    ListNode* l5 = new ListNode(1, l4);
    ListNode* l6 = new ListNode(1, l5);
    ListNode* l7 = new ListNode(1, l6);

    printList(l7);

    cout << endl;
    Solution so;
    ListNode* k =    so.deleteDuplicates(l7);
    cout << endl;
    printList(k);
}

