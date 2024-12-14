class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode* lessHead = new ListNode(-1); // Dummy head for "less than x" list
        ListNode* greaterHead = new ListNode(-1); // Dummy head for "greater than or equal to x" list
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Properly terminate the "greater" list to avoid cycles
        greater->next = nullptr;

        // Connect the two lists
        less->next = greaterHead->next;

        return lessHead->next;
    }
};
