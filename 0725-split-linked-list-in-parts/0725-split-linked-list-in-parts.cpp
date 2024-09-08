
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (!head) return vector<ListNode*>(k, nullptr);

        int len = 0;
        ListNode* temp = head;
        while (temp) {
            ++len;
            temp = temp->next;
        }

        int each = len / k;
        int leftOver = len % k;

        vector<ListNode*> ans(k, nullptr);
        ListNode* curr = head;

        for (int i = 0; i < k && curr; ++i) {
            ans[i] = curr;  
            int partSize = each + (leftOver > 0 ? 1 : 0);  // Adjust size for leftover nodes

            leftOver--; 
            
            for (int j = 1; j < partSize; ++j) {
                if (curr) curr = curr->next;
            }

            
            if (curr) {
                ListNode* next = curr->next;  // Save the next part's head
                curr->next = nullptr;         // Terminate current part
                curr = next;                  // Move to the next part
            }
        }

        return ans;
    }
};
