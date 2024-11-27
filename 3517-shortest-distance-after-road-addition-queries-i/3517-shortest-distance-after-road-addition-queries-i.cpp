class Solution {
    unordered_map<int,vector<int>>adj;
    int m;
    int dijk(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>dist(m,1e9);
        dist[0]=0;
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            if(front.second==m-1) return front.first;
            for(auto&j:adj[front.second]){
                if(dist[front.second]+1<dist[j]){
                    pq.push({dist[front.second]+1,j});
                    dist[j]=dist[front.second]+1;
                }
            }
        }
        return 1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
      vector<int>ans;
      for(int i=0;i<n-1;++i){
        adj[i].push_back(i+1);
      }
        m=n;
      for(auto&i:queries){
        adj[i[0]].push_back(i[1]);
        ans.push_back(dijk());
      }
      return ans;
    }
};