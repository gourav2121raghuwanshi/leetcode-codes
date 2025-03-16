class Solution {
    // appraoch : for each element of nums find how many queries will be
    // required maximum of these is our answer if not possible for any element
    // of nums : return -1;
    int dp[1001][1001];
    int solve(int i, vector<vector<int>>& queries, int target, int idx) {
        if (target == 0)
            return i; // these many queries have been taken for curent NUMS[idx]
        if (target < 0 || i  >= queries.size())
            return 1e6;

        if(dp[i][target]!=-1) return dp[i][target];
        int ntake = solve(i + 1, queries, target, idx);
        int taken = 1e6;
        if (queries[i][0] <= idx && idx <= queries[i][1]) {
            taken = solve(i + 1, queries, target - queries[i][2], idx);
        }
        return dp[i][target] =  min(taken, ntake);
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = -1;

        for (int i = 0; i < nums.size(); ++i) {
            memset(dp,-1,sizeof(dp));
            ans = max(ans, solve(0, queries, nums[i], i));
            if (ans > queries.size())
                return -1;
        }
        return ans;
    }
};