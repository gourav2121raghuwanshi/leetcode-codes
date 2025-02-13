
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
       vector<vector<int>>adj(n);
       for(auto&i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
       }
    int ans=1e9;

    for(int i=0;i<n;++i){
        queue<pair<int,int>>q;
        q.push({i,-1});
        vector<int>dist(n,-1);
        dist[i]=0;
        while(!q.empty()){
            // int size=q.size();
            // while(size--){
                auto front=q.front(); q.pop();
                int node=front.first;
                int par=front.second;
                for(auto&j:adj[node]){
                    if(j==par) continue;
                if(dist[j]==-1){
                    dist[j]=dist[node]+1;
                    q.push({j,node});
                }else{
                    ans=min(ans,dist[j]+dist[node]+1);
                }
                }
        }
    }

    return ans==1e9?-1:ans;
        }
};
