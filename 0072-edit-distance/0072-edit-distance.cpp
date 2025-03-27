class Solution {
    int dp[501][501];
    int solve(int i,int j,string&a,string&b){
        if(i>=a.size() && j>=b.size()) return 0;
        if(i>=a.size()) return b.size()-j;
        if(j>=b.size()) return a.size()-i;

        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j] = solve(i+1,j+1,a,b);
        else{
            // ins
            int ins=solve(i,j+1,a,b);
            // del
            int del=solve(i+1,j,a,b);
            // rep
            int replace=solve(i+1,j+1,a,b);
            return dp[i][j] = min({ins,del,replace})+1;
        }
    }
public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2);
    }
};