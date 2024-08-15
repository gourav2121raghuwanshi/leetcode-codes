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
    int len(ListNode* temp) {
        int c = 0;
        while (temp) {
            ++c;
            temp = temp->next;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        int l = len(head);
        if (l < k)
            return head;
        int c = 1;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (c <= k) {
            ++c;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if (curr)
            head->next = reverseKGroup(curr, k);

        return prev;
    }
};