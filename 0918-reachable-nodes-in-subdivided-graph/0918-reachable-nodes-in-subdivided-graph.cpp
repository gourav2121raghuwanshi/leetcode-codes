class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMove, int n) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto&i:edges){
            int a=i[0];
            int b=i[1];
            int c=i[2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        q.push({0,0});
        int ans=0;
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        while(!q.empty()){
            auto [cost,node]=q.top();
            q.pop();

            for(auto&j:adj[node]){
                if(dist[j.first]>cost+1+j.second && maxMove>=cost+1+j.second){
                    dist[j.first]=cost+1+j.second;
                    q.push({cost+1+j.second,j.first});
                }
            }
        }
        
        for(auto&i:dist){
            if(i<=maxMove)++ans;
        }
        for(auto&i:edges){
            int a=i[0];
            int b=i[1];
            int c=i[2];
            int ca=max(0,maxMove-dist[a]);
            int cb=max(0,maxMove-dist[b]);
            ans+=min(ca+cb,c);

        }
        return ans;
    }
};