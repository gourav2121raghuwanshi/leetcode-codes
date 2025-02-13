class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        //     matrix    // nXm
        //               // val = (i,j) = i*m+j
        //               // row  = val/m
        //               // col  = val%m


        int n=moveTime.size();
        int m=moveTime[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,1,0}); // cost,c,val(row,col)
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;

        vector<pair<int,int>>dir={
            {0,1},{0,-1},{-1,0},{1,0}
        };
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int cost=front[0];
            int c=front[1];
            int val=front[2];
            int row=val/m;
            int col=val%m;

            if(row==n-1 && col==m-1) return cost;
            for(auto&j:dir){
                int r=row+j.first;
                int cl=col+j.second;
                if(r>=0 && cl>=0 && r<n && cl<m){
                    int newCost = max(cost+c,moveTime[r][cl]+c);
                    if(newCost<dist[r][cl]){
                        dist[r][cl]=newCost;
                        int newc=c==1?2:1;
                        int nidx=r*m+cl;
                        pq.push({newCost,newc,nidx});
                    }
                }
            }
        }
        return -1;
    }
};