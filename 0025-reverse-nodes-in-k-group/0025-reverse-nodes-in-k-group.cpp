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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len=0;
        ListNode*t=head;
        while(t){
            ++len;
            t=t->next;
        }
        if(len<k) return head;
        int c=1;
        ListNode*curr=head;
        ListNode*next,*prev=NULL;
        while(curr && c<=k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            ++c;
        }
        // if(prev) cout<<prev->val<<endl;
        // if(curr) cout<<curr->val<<endl;
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};