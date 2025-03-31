class Solution {
    vector<vector<int>> adj;
    
    void dfs(int node,  vector<bool>& vis,vector<vector<int>>& isConnected) {
        if (vis[node]) return;
        vis[node] = true;
        
       for(int j=0;j<isConnected[node].size();++j){
        if(j!=node && isConnected[node][j]) dfs(j,vis,isConnected);
       }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
     
        vector<bool> vis(isConnected.size(), false); // Explicit `false`
        int ans=0;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!vis[i]) {
                ++ans;
                dfs(i, vis, isConnected);
            }
        }
        return ans;
    }
};