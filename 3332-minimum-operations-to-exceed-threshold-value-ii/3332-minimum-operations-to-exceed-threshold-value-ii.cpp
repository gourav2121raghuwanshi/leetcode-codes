class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<>>pq;
        for(auto&i:nums){
            pq.push(i);
        }
        int ans=0;
        while(!pq.empty() && pq.top()<k){
            long long t=pq.top();
            pq.pop();
            long long st=pq.top();
            pq.pop();
            ++ans;
            pq.push(min(t,st)*2+max(t,st));
        }
        return ans;
    }
};