class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>ans(n,vector<int>(m,1e9));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int cnt=1;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto front=q.front();
                int r=front.first;
                int c=front.second;
                q.pop();
                for(int k=0;k<4;++k){
                    int dr=r+row[k];
                    int dc=c+col[k];
                    if(dr>=0 && dc>=0 && dr<n && dc<m && mat[dr][dc]==1){
                        ans[dr][dc]=min(ans[dr][dc],cnt);
                        q.push({dr,dc});
                        mat[dr][dc]=0;
                    }
                }
            }
            ++cnt;
        }
        return ans;
    }
};