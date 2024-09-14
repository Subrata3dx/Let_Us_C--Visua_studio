
#include <iostream>
using namespace std;




 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  void printList(ListNode* h)
  {
      while (h)
      {
          cout << h->val<<" ";
          h = h->next;
      }
  }

  /* I tried using vector as storing media but it timed out
  
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head==NULL)
        return nullptr;

        if(left==right)
        return head;

        ListNode* temp = head;
        vector<int> v1;
        while(temp)
        {
            if(temp->val == left)
            {
                while(temp!=NULL && temp->val<=right)
                {
                    v1.push_back(temp->val);
                    temp = temp->next;
                }

            }
            temp = temp->next;
        }


        temp = head;
        while(temp)
        {
            if(temp->val == left)
            {
                auto a = v1.crbegin();
                while(temp!=NULL && temp->val <= right)
                {
                    temp->val = v1[*a];
                    if(a<v1.crend())
                    a++;
                    temp = temp->next;
                }

            }
            temp = temp->next;
        }
        return head;
    }
};
  */
 
  

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {


        if (left == right || head == NULL)
        {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        int i = 0;
        for (i = 0; i < left - 1; i++)
        {
            prev = prev->next;

        }
        ListNode* curr = prev->next;
        for (i = 0; i < (right - left); i++)
        {
            ListNode* future = curr->next;
            curr->next = future->next;
            future->next = prev->next;
            prev->next = future;

        }

        return dummy->next;


    }
};


int main()
{
    
    ListNode* l1 = new ListNode(70);
    ListNode* l2 = new ListNode(60, l1);
    ListNode* l3 = new ListNode(50, l2);
    ListNode* l4 = new ListNode(40, l3);
    ListNode* l5 = new ListNode(30, l4);
    ListNode* l6 = new ListNode(20, l5);
    ListNode* l7 = new ListNode(10, l6);

    printList(l7);

    cout << endl;
    Solution so;

    so.reverseBetween(l7, 3, 6);

    printList(l7);
    return 0;
    

}


