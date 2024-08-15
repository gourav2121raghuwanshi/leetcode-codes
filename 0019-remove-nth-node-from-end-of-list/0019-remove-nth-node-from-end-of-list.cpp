/*
To enhance efficiency, we will involve two pointers, a fast pointer and a slow
pointer. The fast-moving pointer will initially be exactly N nodes ahead of the
slow-moving pointer. After which, both of them will move one step at a time.
When the fast pointer reaches the last node, i.e., the L-th node, the slow is
guaranteed to be at the (L-N)-th node, where L is the total length of the linked
list.


*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*prev=head;
        for(int i=1;i<=n;i++) fast=fast->next;

        while(fast){
            prev=slow;
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==head) return head->next;
        prev->next=slow->next;


        return head;
    }
};