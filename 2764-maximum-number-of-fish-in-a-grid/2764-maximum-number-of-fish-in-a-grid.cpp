class Solution {
    int ans=0;
    int c=0;
    vector<vector<int>>vis;
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0 || vis[i][j]) return;

        c+=grid[i][j];
        vis[i][j]=true;
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector<pair<int,int>>dir={
            {0,1},{0,-1},{1,0},{-1,0}
        };
        n=grid.size();
        m=grid[0].size();
        vis.resize(n,vector<int>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    c=0;
                    dfs(i,j,grid);
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};