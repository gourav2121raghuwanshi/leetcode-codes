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
    class comp {
    public:
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(auto&i:lists){
            if(i!=NULL)
            pq.push(i);
        }
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            tail->next=front;
            tail=tail->next;
            if(front->next){
                pq.push(front->next);
            }
        }
        tail->next=NULL;
        return ans->next;
    }
};