class Solution {

public:
    bool solve(int count, int n, vector<int>& nums, int k, int sum,
               vector<bool>& vis, int currSum,int idx) {
        if (count == k ) {

            return 1;
        }
        if (currSum == sum) {
            return solve(count + 1, n, nums, k, sum, vis, 0, 0);
        }
        if (currSum > sum) {
            return false;
        }
        int cs = 0;
        for (int i = idx; i < n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                if (solve(count, n, nums, k, sum, vis, currSum + nums[i], i+1))
                    return 1;
                vis[i] = 0;
                 if(currSum==0) break;
            }
           
        }
        return 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1)
            return true;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0 || nums.size() < k)
            return false;
        vector<bool> vis(nums.size(), false);
        
        return solve(0, nums.size(), nums, k, sum / k, vis, 0, 0);
        
    }
};