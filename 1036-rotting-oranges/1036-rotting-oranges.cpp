class Solution {
    using v=vector<int>;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<v>q;
        int ans=0;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        int oc=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=0;
                }else if(grid[i][j]==1) ++oc;
            }
        }
        int ovis=0;
        while(!q.empty()){
            bool f=false;
            int size=q.size();
            while(size--){
                auto front=q.front();
                q.pop();
                int x=front[0];
                int y=front[1];

                for(int k=0;k<4;++k){
                    int dr=row[k]+x;
                    int dc=col[k]+y;
                    if(dr>=0 && dc>=0 && dr<n && dc<m && grid[dr][dc]==1){
                        f=true;
                        grid[dr][dc]=0;
                        q.push({dr,dc});
                        ++ovis;
                    }
                }
            }
            if(f){
                ++ans;
            }else break;
        }
        if(oc==ovis)
        return ans;
        return -1;
    }
};