class Solution {
    #define p pair<int,int>
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>>adj;
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>d1(n+1,INT_MAX);
        vector<int>d2(n+1,INT_MAX);

        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,1});

        
        while(!pq.empty()){
            auto [dist,node]=pq.top();
            pq.pop();

            if(node==n && d2[n]!=INT_MAX) return d2[n];
            int div=dist/change;
            if(div%2==1){
                dist=(div+1)*change;
            }
            for(auto&i:adj[node]){
                if(d1[i]>dist+time){
                    d2[i]=d1[i];
                    d1[i]=dist+time;
                    pq.push({d1[i],i});
                }else if(dist+time!=d1[i] && dist+time<d2[i]){
                    d2[i]=dist+time;
                    pq.push({d2[i],i});
                }
            }
        }
        return -1;
    }
};