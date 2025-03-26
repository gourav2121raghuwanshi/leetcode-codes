
class Solution {
    int dp[103][103];
    int solve(int s, int e, vector<int>& cuts) {
        if (s >= e)
            return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int ans = 1e9;
        for (int i = s; i < e; ++i) {
            ans = min(ans, cuts[i] - cuts[s - 1] + cuts[e] - cuts[i] +
                               solve(s, i, cuts) + solve(i + 1, e, cuts));
        }
        return  dp[s][e] = ans;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp,-1,sizeof(dp));
        return solve(1, cuts.size() - 1, cuts);
    }
};