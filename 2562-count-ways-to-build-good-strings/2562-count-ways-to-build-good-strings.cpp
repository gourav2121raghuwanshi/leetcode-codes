class Solution {
    const int mod=1e9+7;
    int dp[100002];
    long long solve(int i,int low, int high, int zero, int one){
        if(i>high) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=0;
        if(i<=high && i>=low) ++ans;
        ans=(ans+solve(i+zero,low,high,zero,one)+solve(i+one,low,high,zero,one))%mod;
        return dp[i] = ans;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return solve(0,low,high,zero,one);
    }
};