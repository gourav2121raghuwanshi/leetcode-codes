class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using p = pair<int, int>;
        unordered_map<int, int> freq;
        for (auto& i : nums) {
            ++freq[i];
        }
        priority_queue<p, vector<p>, greater<>> pq;
        for (auto& i : freq) {
            pq.push({i.second, i.first});
            if (pq.size() > k)
                pq.pop();
        }
    
    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
}
;