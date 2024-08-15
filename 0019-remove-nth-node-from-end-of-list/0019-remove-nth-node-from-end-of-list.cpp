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
    int len(ListNode*head){
        int c=0;
        while(head){
            ++c;
            head=head->next;
        }
        return c;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;
        int l=len(head);
        int fromStart=l-n;
        // cout<<fromStart<<endl;
        if(fromStart==0) return head->next;
        ListNode*curr=head;
        ListNode*prev;
        while(curr && fromStart--){
            prev=curr;
            curr=curr->next;
        }
        if(curr && prev)
        prev->next=curr->next;
        return head;

    }
};