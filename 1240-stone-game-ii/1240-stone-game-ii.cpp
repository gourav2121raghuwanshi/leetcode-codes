class Solution {
    int memo[101][101][2];
    int solve(int i, int m, vector<int>& piles, bool turn) {
        if (i >= piles.size()) return 0;
        if (memo[i][m][turn] != -1) return memo[i][m][turn];

        int ans = turn ? -1: INT_MAX;
        int take = 0;
        for (int x = i; x < min(2 * m + i, (int)piles.size()); ++x) {
            take += piles[x];
            if (turn) {
                ans = max(ans, take + solve(x + 1, max(m, x - i + 1), piles, !turn));
            } else {
                ans = min(ans, solve(x + 1, max(m, x - i + 1), piles, !turn));
            }
        }
        return memo[i][m][turn] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(memo,-1,sizeof(memo));
        return solve(0, 1, piles, true);
    }
};
