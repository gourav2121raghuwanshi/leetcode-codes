class Solution {
    
    int dp[16][(1<<16)];
    int solve(int j,int val,int n){
        if(j==n+1) return 1;
        if(j>n+1) return 0;
        if(dp[j][val]!=-1) return dp[j][val];
        int v=0;
        for(int i=1;i<=n;++i){
            if(val&(1<<i) && (i%j==0 || j%i==0)){
                val^=(1<<i);
                v+=solve(j+1,val,n);
                val^=(1<<i);
            }
        }
        return dp[j][val]=v;

    }
public:
    int countArrangement(int n) {
        int val=(1<<(n+1))-1;
        memset(dp,-1,sizeof(dp));
        return solve(1,val,n);
    }
};