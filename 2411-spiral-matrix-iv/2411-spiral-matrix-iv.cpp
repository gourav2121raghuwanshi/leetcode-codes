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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> mat(m, vector<int>(n, -1));
        int l = 0, t = 0, b = m - 1, r = n - 1;
        int dir = 0;
        while (l <= r && t <= b && head) {
            if (dir == 0) {
                for (int i = l; i <= r; ++i) {
                    if (!head)
                        break;
                    mat[t][i] = head->val;
                    head = head->next;
                }
                ++t;
            } else if (dir == 1) {
                for (int i = t; i <= b; ++i) {
                    if (!head)
                        break;
                    mat[i][r] = head->val;
                    head = head->next;
                }
                --r;
            } else if (dir == 2) {
                for (int i = r; i >= l; --i) {
                    if (!head)
                        break;
                    mat[b][i] = head->val;
                    head = head->next;
                }
                --b;
            } else {
                for (int i = b; i >= t; --i) {
                    if (!head)
                        break;
                    mat[i][l] = head->val;
                    head = head->next;
                }
                ++l;
            }
            dir = (dir + 1) % 4;
        }
        return mat;
    }
};