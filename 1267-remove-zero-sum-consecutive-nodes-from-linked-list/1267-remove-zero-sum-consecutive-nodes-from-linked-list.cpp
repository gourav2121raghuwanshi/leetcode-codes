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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return nullptr;
        unordered_map<int,ListNode*>mp;
        int sum=0;
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        mp[0]=dummy;
        while(head){
            sum+=head->val;
            if(mp.count(sum)){
                ListNode*prev=mp[sum];
                ListNode*temp=prev;
                int cs=sum;
                while(prev!=head){
                    prev=prev->next;
                    cs+=prev->val;
                    if(prev!=head){
                        mp.erase(cs);
                    }
                }
                temp->next=head->next;
            }else{
                mp[sum]=head;
            }
            head=head->next;
        }

        return dummy->next;
    }
};