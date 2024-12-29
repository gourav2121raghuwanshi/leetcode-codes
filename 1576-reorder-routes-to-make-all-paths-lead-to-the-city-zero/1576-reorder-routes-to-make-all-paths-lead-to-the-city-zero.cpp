class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans=0;
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto&i:connections){
            int a=i[0];
            int b=i[1];
            adj[a].push_back({b,0});
            adj[b].push_back({a,1});
        }
        queue<int>q;
        q.push(0);
        vector<bool>vis(n,false);
        vis[0]=true;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto&j:adj[front]){
                int node=j.first;
                int zo=j.second;
                if(!vis[node]){
                    if(zo==0){
                        ++ans;
                    }
                    q.push(node);
                    vis[node]=1;
                }
            }
        }
        return ans;
    }
};