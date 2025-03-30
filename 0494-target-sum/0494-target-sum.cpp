class Solution {
    int n;
    string getKey(int i,int sum){
        return to_string(i)+":"+to_string(sum);
    }
    unordered_map<string,int>dp;
    int solve(int i, vector<int>& nums, int sum, int target) {
        if (i == n) {
            return target == sum;
        }
        string k=getKey(i,sum);
        if(dp.count(k)) return dp[k];
        int takePluse = solve(i + 1, nums, sum + nums[i], target);
        int takeMinus = solve(i + 1, nums, sum - nums[i], target);
        return dp[k] = takePluse + takeMinus;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        n = nums.size();
        return solve(0, nums, 0, target);
    }
};