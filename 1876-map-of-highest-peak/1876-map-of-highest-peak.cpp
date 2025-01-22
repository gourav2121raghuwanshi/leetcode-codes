class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j]) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
      

        int c=1;
        vector<pair<int,int>>dir={
            {0,1},{0,-1},{1,0},{-1,0}
        };
        while (!q.empty()) {
            int s=q.size();
            while(s--){
                auto [x,y]=q.front();
                q.pop();
                for(auto&[i,j]:dir){
                    int dr=x+i;
                    int dc=y+j;
                    if(dr>=0 && dc>=0 && dr<n && dc<m && ans[dr][dc]==-1){
                        ans[dr][dc]=c;
                        q.push({dr,dc});
                    }
                }
            }
            ++c;
        }

        return ans;
    }
};