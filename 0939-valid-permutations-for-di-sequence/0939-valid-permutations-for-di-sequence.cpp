class Solution {
    int num;
    const int mod = 1e9 + 7;
    // unordered_map<string, int> mp;

    // string getKey(int i, int prev, vector<bool>& vis) {
    //     string s;
    //     s.push_back(i + '0');
    //     s.push_back(':');
    //     s.push_back(prev + '0');
    //     s.push_back(':');
    //     for (auto i : vis) {
    //         if (i == false) {
    //             s.push_back('0');
    //             s.push_back(':');
    //         } else {
    //             s.push_back('1');
    //             s.push_back(':');
    //         }
    //     }
    //     return s;
    // }
    // unordered_map<string, int> dp;
    int dp[202][202];
    int solve(int i, int prev, string& s, vector<bool>& vis) {
        if (i >= s.size())
            return 1;
        if(dp[i][prev]!=-1) return dp[i][prev];
        // string key = getKey(i, prev, vis);
        // if (dp.count(key))
        //     return dp[key];
        int ans = 0;
        if (s[i] == 'I') {
            for (int j = prev + 1; j <= num; j++) {
                if (!vis[j]) {
                    vis[j] = 1;
                    ans = (ans + solve(i + 1, j, s, vis)) % mod;
                    vis[j] = 0;
                }
            }
        } else {
            for (int j = 0; j < prev; j++) {
                if (!vis[j]) {
                    vis[j] = 1;
                    ans = (ans + solve(i + 1, j, s, vis)) % mod;
                    vis[j] = 0;
                }
            }
        }

        return dp[i][prev] = ans;
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