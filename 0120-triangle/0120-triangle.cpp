class Solution {
    int n,m;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& triangle){
        if(i==n) return 0;
        if(j>=triangle[i].size()) return 1e7;

        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = triangle[i][j]+min(solve(i+1,j,triangle),solve(i+1,j+1,triangle));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        m=triangle[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,triangle);
    }
};