class Solution {
    unordered_map<int,vector<int>>adj;
    int solve(int node,int par, vector<bool>& hasApple){
        int t=0;
        for(auto&i:adj[node]){
            if(i==par) continue;
            int child=solve(i,node,hasApple);
            if(hasApple[i] || child){
                t+=child+2;
            }
        }
        return t;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return solve(0,-1,hasApple);
    }
};