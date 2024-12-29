class Solution {
    const int mod=1e9+7;
    int dp[1001][1001];
    int solve(int i,int j,string &target,vector<vector<int>>&freq){
        if(i>=target.size()) {
            return 1;
        }
        if(j>=freq.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(freq[j][target[i]-'a']>0)
        take=(freq[j][target[i]-'a']*1LL*solve(i+1,j+1,target,freq))%mod;
        int ntake=solve(i,j+1,target,freq);
        return dp[i][j] = (take+ntake)%mod;
    }

public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        vector<vector<int>>freq(n,vector<int>(26,0));
        

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words.size(); ++j) {
                freq[i][words[j][i] - 'a']++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,0,target,freq);
    }
};