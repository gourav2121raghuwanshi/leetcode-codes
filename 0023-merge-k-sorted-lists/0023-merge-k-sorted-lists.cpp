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
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode*head=nullptr;
        ListNode*tail=nullptr;
        for(auto&i:lists){
            if(i!=nullptr) pq.push(i);
        }
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            if(head==nullptr){
                head=tail=t;
            }else{
                tail->next=t;
                tail=tail->next;
            }
            if(t->next) pq.push(t->next);
        }
        return head;
    }
};