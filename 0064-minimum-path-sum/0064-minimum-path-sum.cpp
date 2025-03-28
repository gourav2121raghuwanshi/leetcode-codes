class Solution {
    int n,m;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1) return grid[n-1][m-1];
        if(i>=n || j>=m) return 1e7;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e7;

        return dp[i][j] = grid[i][j]+min(solve(i+1,j,grid),solve(i,j+1,grid));
    
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,1e6,sizeof(dp));
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                if(i==n-1 && j==m-1) continue;
                else dp[i][j] = grid[i][j]+min(dp[i+1][j] ,dp[i][j+1]);
            }
        }

        return dp[0][0];
        // return solve(0,0,grid);
    }
};