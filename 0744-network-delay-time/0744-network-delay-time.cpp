class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto&i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n+1,1e9);
        dist[0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            vector<int>f=pq.top(); pq.pop();
            int dis=f[0];
            int node=f[1];
            for(auto&k:adj[node]){
                int nbr=k.first;
                int wt=k.second;
                if(dist[nbr]>dis+wt){
                    dist[nbr]=dis+wt;
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        for(auto&i:dist){
            // cout<<i<<' ';
            if(i==1e9) return -1;
        }
        return *max_element(dist.begin(),dist.end());
    }
};