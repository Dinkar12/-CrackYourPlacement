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
    void reorderList(ListNode* head) {
        // Number of nodes
        int n=0;
        ListNode* temp = head;
        while(temp!=nullptr){
            temp=temp->next;
            n++;
        }
        ListNode* temp1 = head;
        // Will be used to move in reverse direction
        vector<ListNode*> prevs;
        temp=head;
        ListNode* prev = nullptr;
        while(temp!=nullptr){
            prevs.push_back(prev);
            prev= temp;
            temp=temp->next;
        }
        ListNode* temp2 = head;
        while(temp2->next){
            temp2=temp2->next;
        }
        int cnt=0;
        int index = n-1;
        while(cnt<n/2 && temp1 && temp2){
            ListNode* next1 = temp1->next;
            ListNode* next2 = prevs[index];
            cnt++;
            temp1->next = temp2;
            temp2->next = next1;
            temp1=next1;
            temp2=next2;
            index--;            
        }
        temp = head;
        // A cycle will always be formed
        unordered_map<ListNode*,int> mapp;
        while(temp!=nullptr){
            if(mapp[temp->next] == 1){
                temp->next = nullptr;
            }
            mapp[temp] = 1;
            temp=temp->next;
        }
        

    }
};