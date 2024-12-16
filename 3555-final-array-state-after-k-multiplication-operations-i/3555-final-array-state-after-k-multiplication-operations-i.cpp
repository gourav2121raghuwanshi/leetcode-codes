class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }

        while (k--) {
            auto top = pq.top();
            pq.pop();
            pq.push({top.first * multiplier, top.second});
        }

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            nums[top.second] = top.first;
        }

        return nums;
    }
};
