class Solution {
    unordered_map<int,vector<int>>adj;
    int ans=0;
    long long dfs(int i,vector<int>& values, int k,vector<bool>&vis){
        vis[i]=true;
        long long sum=values[i];
        for(auto&j:adj[i]){
            if(vis[j]) continue;
            sum+=dfs(j,values,k,vis);
            sum%=k;
        }
        if(sum%k==0){
            ++ans;
            return 0;
        }
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>vis(n,false);
        dfs(0,values,k,vis);
        return ans;
    }
};