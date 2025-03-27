class Solution {
    int dp[1001][1001];
    int solve(string&a,string&b,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j] = 1+solve(a,b,i-1,j-1);
        }else{
            return dp[i][j] = max(solve(a,b,i,j-1),solve(a,b,i-1,j));
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        string a=s;
        reverse(a.begin(),a.end());
        memset(dp,-1,sizeof(dp));
        return solve(a,s,a.size()-1,s.size()-1);
    }
};