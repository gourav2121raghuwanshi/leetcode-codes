class Solution {
    int dp[501][501];
    int solve(int s, int e, vector<int>& piles) {
        if (s > e)
            return 0;
        if (dp[s][e] != -1)
            return dp[s][e];
        int takes =
            piles[s] + min(solve(s + 1, e - 1, piles), solve(s + 2, e, piles));
        int takee =
            piles[e] + min(solve(s + 1, e - 1, piles), solve(s, e - 2, piles));
        return dp[s][e] = max(takes, takee);
    }

public:
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(piles.begin(), piles.end(), 0);
        int alice = solve(0, piles.size() - 1, piles);
        return alice >= sum - alice;
    }
};