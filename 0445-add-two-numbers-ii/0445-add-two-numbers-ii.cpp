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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* forward = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(0);
        ListNode* newTemp = newHead;

        l1 = reverseList(l1);
        l2 = reverseList(l2);

        int data = 0;
        int carry = 0;

        while(l1 != NULL || l2 != NULL)
        {
            data = (l1? l1-> val : 0) + (l2? l2-> val : 0) + carry;
            carry = data / 10;
            data = data % 10;
            newTemp-> next = new ListNode(data);
            newTemp = newTemp-> next;
            if(l1)
            {
                l1 = l1-> next;
            }
            if(l2)
            {
                l2 = l2-> next;
            }
        }
        if(carry > 0)
        {
            newTemp-> next = new ListNode(carry);
        }
        newHead = reverseList(newHead-> next);
        return newHead;
    }
};