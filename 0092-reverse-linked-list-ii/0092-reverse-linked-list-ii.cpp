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
    ListNode*rev(ListNode*head){
        if(!head || !head->next) return head;
        ListNode*curr=head;
        ListNode*prev=nullptr;
        ListNode*next=nullptr;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode*temp=head;
        ListNode*tp=nullptr;
        for(int i=1;i<left;++i){
            tp=temp;
            temp=temp->next;
        }
        ListNode*tail=temp;
           for(int i=left;i<right;++i){
            tail=tail->next;
           }
        ListNode*last= nullptr;
        if(tail) last = tail->next;

        tail->next=NULL;


        ListNode*reverse=rev(temp);
        if(tp==nullptr && last==nullptr) return reverse;

        if(tp)
        tp->next=reverse;

        if(left==1){
            head=reverse;
        }
        tail=reverse;
        while(tail->next) tail=tail->next;
        if(last){
            tail->next=last;
        }

        return head;
     
     
     
    }
};