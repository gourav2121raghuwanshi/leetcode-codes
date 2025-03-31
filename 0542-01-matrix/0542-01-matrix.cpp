class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        vector<pair<int,int>>dir={
            {0,1},{0,-1},{1,0},{-1,0}
        };
        int c=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto front=q.front(); q.pop();
                int x=front.first;
                int y=front.second;
                for(auto&k:dir){
                    int dx=k.first+x;
                    int dy=k.second+y;
                    if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && mat[dx][dy]==1){
                        vis[dx][dy]=true;
                        ans[dx][dy]=c;
                        q.push({dx,dy});
                    }
                }
            }
            ++c;
        }
        return ans;
    }
};