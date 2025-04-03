class Solution {
    int dp[101][101];
    bool solve(int lpc, int i, string& s) {
        if (i >= s.size()) {
            return lpc == 0;
        }
        if(lpc<0) return false;
        if (dp[i][lpc] != -1)
            return dp[i][lpc];
        if (s[i] == '(') {
            return dp[i][lpc] = solve(lpc + 1, i + 1, s);
        } else if (s[i] == ')') {
            return dp[i][lpc] = solve(lpc-1, i + 1, s);
        } else {
            return dp[i][lpc] = solve(lpc + 1, i + 1, s) ||
                                     solve(lpc-1, i + 1, s) ||
                                     solve(lpc, i + 1, s);
        }
    }

public:
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return solve( 0, 0, s);
    }
};