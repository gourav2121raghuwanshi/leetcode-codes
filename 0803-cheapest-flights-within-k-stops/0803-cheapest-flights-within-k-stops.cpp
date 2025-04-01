class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        queue<vector<int>>q;
        q.push({0,0,src}); // cost/stops/node
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(front[1]>k) continue;
            int node=front[2];
            int dis=front[0];
            int stops=front[1];
            for(auto&j:adj[node]){
                if(dist[j.first]>dis+j.second){
                    dist[j.first]=dis+j.second;
                    q.push({dist[j.first],stops+1,j.first});
                }
            }
        }

        return dist[dst]==1e9?-1:dist[dst];
    }
};