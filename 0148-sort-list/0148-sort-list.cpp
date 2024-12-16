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
    ListNode* merge(ListNode* first, ListNode* second) {
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;

        while (first && second) {
            if (first->val < second->val) {
                tail->next = first;
                tail = tail->next;
                 first = first->next;
            } else {
                tail->next = second;
                tail = tail->next;
                second = second->next;
            }
        }
        if (first)
            tail->next = first;
        if (second)
            tail->next = second;
        return ans->next;
    }
    ListNode* ms(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode*prev=head;
        while (fast && fast->next) {
            prev=slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next=nullptr;
        ListNode*mid=slow;
        // slow->next=nullptr;
        ListNode*left=ms(head);
        ListNode*right=ms(slow);

        head=merge(left,right);
        return head;
    }

public:
    ListNode* sortList(ListNode* head) { return ms(head); }
};