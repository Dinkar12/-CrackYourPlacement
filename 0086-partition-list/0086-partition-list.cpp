/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = NULL,*curr1 = NULL;
        ListNode* h2 = NULL,*curr2 = NULL;
        ListNode* curr = head,*ans = NULL;
        int count = 0;
        while(curr)
        {
            if(curr->val<x)
            {
                if(!curr1) curr1 = curr;
                else 
                {
                  curr1->next = curr;
                  curr1 = curr;
                }
                h1 = (!h1) ? curr : h1;
            }
            else
            {
                if(!curr2) curr2 = curr;
                else
                {
                    curr2->next = curr;
                    curr2 = curr;
                }
                h2 = (!h2) ? curr : h2;
            }
            curr = curr->next;
            if(curr1) curr1->next =  NULL;
            if(curr2) curr2->next =  NULL;
        }
        if(curr1)
        {
            curr1->next = h2;
            return h1;
        }
        return h2; 
    }
};