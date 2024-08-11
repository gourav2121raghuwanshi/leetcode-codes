class Solution {
    int dp[1001][1001];
    int solve(int i,int j,string &a, string &b){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j] = 1+solve(i-1,j-1,a,b);
        else return dp[i][j] = max(solve(i,j-1,a,b),solve(i-1,j,a,b));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(text1.size()-1,text2.size()-1,text1,text2);
    }
};