class Solution {
    int dp[2001][2001];
    bool solve(int i, int j, string& s, string& p) {
        if (i >= s.size()) {
            if (j == p.size())
                return 1;
            for (int k = j; k < p.size(); ++k) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (j >= p.size())
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j]) {
            return dp[i][j] = solve(i + 1, j + 1, s, p);
        } else if (p[j] == '?') {
            return dp[i][j] = solve(i + 1, j + 1, s, p);
        } else if (p[j] == '*') {
            return dp[i][j] =
                       solve(i + 1, j, s, p) || solve(i + 1, j + 1, s, p) || solve(i,j+1,s,p);
        } else
            return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};