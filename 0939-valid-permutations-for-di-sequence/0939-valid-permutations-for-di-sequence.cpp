class Solution {
    int num;
    const int mod = 1e9 + 7;
    int dp[202][202];
    int solve(int i, int prev, string& s, vector<bool>& vis) {
        if (i >= s.size())
            return 1;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int ans = 0;
        if (s[i] == 'I') {
            for (int j = prev + 1; j <= num; ++j) {
                if (!vis[j]) {
                    vis[j] = 1;
                    ans = (ans + solve(i + 1, j, s, vis)) % mod;
                    vis[j] = 0;
                }
            }
        } else {
            for (int j = 0; j < prev; ++j) {
                if (!vis[j]) {
                    vis[j] = 1;
                    ans = (ans + solve(i + 1, j, s, vis)) % mod;
                    vis[j] = 0;
                }
            }
        }
        if(prev!=-1) return dp[i][prev]=ans;
        return  ans;
    }

public:
    int numPermsDISequence(string s) {
        num = s.size();
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i <= num; ++i) {
            vector<bool> vis(num + 1, false);
            vis[i] = 1;
            ans = (ans + solve(0, i, s, vis)) % mod;
        }
        return ans;
    }
};