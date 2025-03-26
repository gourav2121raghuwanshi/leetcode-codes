class Solution {
    int dp[2502][2501];
    int solve(int prev,int i,vector<int>&v){
        if(i>=v.size()) return 0;
        int take=0;
        int ntake=0;
        if(dp[prev+1][i]!=-1) return dp[prev+1][i];
        if(prev==-1 || v[i]>v[prev]){
            take = 1+solve(i,i+1,v);
        }
        ntake=solve(prev,i+1,v);
        // if(dp[prev][i]!=-1) dp[prev][i] =max(take,ntake);
        return dp[prev+1][i] = max(take,ntake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(-1,0,nums);
    }
};