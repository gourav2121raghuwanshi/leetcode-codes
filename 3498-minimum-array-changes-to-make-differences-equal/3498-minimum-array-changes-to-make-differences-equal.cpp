class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int, int> diff; //abs diff of pair (i,j)
        vector<int> limit; // what max possible diff limit for pair(i,j)

        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int mini = min(nums[i], nums[j]);
            int maxi = max(nums[i], nums[j]);
            // maxi when make mini=0
            // k-mini , when maxi=k
            int maxDiffPossible = max(maxi, k - mini);

            limit.push_back(maxDiffPossible);
            diff[maxi - mini]++;
            --j, ++i;
        }
        sort(limit.begin(), limit.end());
        int ans = 1e9;
        for (auto& i : diff) {
            // we already have i.second numbers with i.first difference
            int already_done = i.second;
            // we need (limit.size()- already with i.second diff )  more one operations 
            int one_operation_req = limit.size() - already_done; 

            // now for two operations we need numbers whose limit is less  than curr diff
            int two_opern = lower_bound(limit.begin(), limit.end(), i.first) -
                            limit.begin();
            ans = min(ans, one_operation_req + two_opern);
        }
        return ans;
    }
};