class Solution {
    // int dp[2001][2001];
    // bool solve(int i, int j, string& s, string& p) {
    //     if (i >= s.size()) {
    //         if (j == p.size())
    //             return 1;
    //         for (int k = j; k < p.size(); ++k) {
    //             if (p[k] != '*')
    //                 return false;
    //         }
    //         return true;
    //     }
    //     if (j >= p.size())
    //         return false;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (s[i] == p[j]) {
    //         return dp[i][j] = solve(i + 1, j + 1, s, p);
    //     } else if (p[j] == '?') {
    //         return dp[i][j] = solve(i + 1, j + 1, s, p);
    //     } else if (p[j] == '*') {
    //         return dp[i][j] = solve(i + 1, j, s, p) ||
    //                           solve(i + 1, j + 1, s, p) ||
    //                           solve(i, j + 1, s, p);
    //     } else
    //         return dp[i][j] = false;
    // }

public:
    bool isMatch(string s, string p) {
        // memset(dp, 0, sizeof(dp));

        int n = s.size();
        int m = p.size();
        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);


        // Base Cases
        prev[m] = 1;
        for (int j = m - 1; j >= 0; --j) {
            if (p[j] == '*')
                prev[j] = prev[j + 1];
            else
                break;
        }
        
        if(n==0 && prev[0]==true) return true;


        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (s[i] == p[j]) {
                    curr[j] = prev[j + 1];
                } else if (p[j] == '?') {
                    curr[j] = prev[j + 1];
                } else if (p[j] == '*') {
                    curr[j] = prev[j] || curr[j + 1];
                } else
                    curr[j] = false;
            }
            prev = curr;
        }
        return curr[0];
    }
};