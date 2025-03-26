
class Solution {
    int dp[103][103];
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        for (int i = 0; i < 103; ++i) {
            for (int j = 0; j < 103; ++j) {
                dp[i][j] = 1e9;
            }
        }
        for (int s = cuts.size() - 1; s >= 1; --s) {
            for (int e = 0; e <= cuts.size() - 1; ++e) {
                if (s >= e) {
                    dp[s][e] = 0;
                } else {
                    int ans = 1e9;
                    for (int i = s; i < e; ++i) {
                        dp[s][e] = min(dp[s][e], cuts[i] - cuts[s - 1] +
                                                     cuts[e] - cuts[i] +
                                                     dp[s][i] + dp[i + 1][e]);
                    }
                }
            }
        }
        return dp[1][cuts.size() - 1];
    }
};