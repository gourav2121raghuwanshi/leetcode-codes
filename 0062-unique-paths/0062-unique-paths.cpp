class Solution {
    int dp[101][101];
    int solve(int i,int j){
        if(i==1 && j==1) return 1;
        if(i<=0 || j<=0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        return  dp[i][j] = solve(i-1,j)+solve(i,j-1);
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n);
    }
};