class Solution {
    long long dp[(int)1e5 + 1];
    long long solve(int i, vector<vector<int>>& questions) {
        if (i >= questions.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        long long take = questions[i][0] + solve(i + questions[i][1] + 1, questions);
        long long ntake = solve(i + 1, questions);
        return dp[i] = max(take, ntake);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        return solve(0, questions);
    }
};