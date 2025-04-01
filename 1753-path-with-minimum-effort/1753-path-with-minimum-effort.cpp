class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  
            
        while(!pq.empty()){
            auto front=pq.top(); pq.pop();
            int dis=front[0];
            int x=front[1];
            int y=front[2];
            if(x==n-1 && y==m-1) return dist[x][y];
            if(dis>dist[n-1][m-1]) continue;
            
            for(auto&k:dir){
                int dx=x+k.first;
                int dy=y+k.second;
                if(dx>=0 && dy>=0 && dx<n && dy<m ){
                    int maxDis=max(dis,abs(heights[dx][dy]-heights[x][y]));
                    if(dist[dx][dy]>maxDis){
                        dist[dx][dy]=maxDis;
                        pq.push({dist[dx][dy],dx,dy});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};