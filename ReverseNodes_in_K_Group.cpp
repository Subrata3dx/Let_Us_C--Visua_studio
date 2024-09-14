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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;

        while (temp)
        {
            count++;
            temp = temp->next;
        }
        if (k > count || k == 1)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        int t = 0;

        while (count - t >= k)
        {
            reverse(prev, head, k);
            for (int i = 0; i < k; i++)
            {
                prev = prev->next;
                head = head->next;
                i++;
            }

            t += k;
        }

        return dummy->next;

    }

    void reverse(ListNode* prev, ListNode* curr, int k)
    {
        for (int i = 0; i < k; i++)
        {
            ListNode* future = curr->next;
            curr->next = future->next;
            future->next = prev->next;
            prev->next = future;
        }
        //return future->next;

    }
};

void printList(ListNode* l)
{
    while (l)
    {
        cout << l->val<<" ";
        l = l->next;
    }
}


int main()
{
    ListNode* l5 = new ListNode(50);
    ListNode* l4 = new ListNode(40, l5);
    ListNode* l3 = new ListNode(30, l4);
    ListNode* l2 = new ListNode(20, l3);
    ListNode* l1 = new ListNode(10, l2);

    printList(l1);
    cout << endl;
    Solution so;
    so.reverseKGroup(l1, 2);
    printList(l1);
    return 0;

}