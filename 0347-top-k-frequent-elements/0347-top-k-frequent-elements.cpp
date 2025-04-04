class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using p = pair<int, int>;
        unordered_map<int,int>freq;
        for(auto&i:nums){
            ++freq[i];
        }
        priority_queue<p> pq;
        for (auto&i:nums) {
            if (freq[i]>0) {
                pq.push({freq[i], i});
                freq[i]=0;
            }
        }
        vector<int> ans;
        while (!pq.empty() && k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};