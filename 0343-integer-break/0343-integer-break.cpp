class Solution {
int dp[59];
int solve(int n){
    if(n<=1) return 1;
    int ans=0;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=n/2;++i){
        ans=max({ans,i*(n-i),i*solve(n-i)});
    }

   return dp[n] = ans;
}
public:
    int integerBreak(int n) {
       memset(dp,-1,sizeof(dp));
        solve(n);

        return dp[n];
    }
};