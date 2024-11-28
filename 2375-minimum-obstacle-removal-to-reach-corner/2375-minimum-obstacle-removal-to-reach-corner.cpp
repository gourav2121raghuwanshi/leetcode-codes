class Solution {
    using p=pair<int,int>;
    int n,m;
    int getIndx(int i,int j){
        return i*m+j;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        int dist[100001];
       for(int i=0;i<100001;i++) dist[i]=INT_MAX;
        dist[0]=0;
        // vector<vector<int>>dist(n,vector<int>(m,1e9));
        // dist[0][0]=0;
        vector<pair<int,int>> dir={
            {0,1},{0,-1},{1,0},{-1,0}
        };
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int dis=front.first;
            int index=front.second;
            int x=index/m;
            int y=index%m;
            if(x==n-1 && y==m-1) return dis;
            for(auto&j:dir){
                int dx=j.first+x;
                int dy=j.second+y;
                int idx=getIndx(dx,dy);
                if(dx>=0 && dy>=0 && dx<n && dy<m ){
                  int ndist=grid[dx][dy]+dis;
                  if(ndist<dist[idx]){
                    dist[idx]=ndist;
                    pq.push({ndist,idx});
                  }   
                }
            }
        }
        return -1;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();