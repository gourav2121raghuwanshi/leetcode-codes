class Solution {
     vector<vector<int>> mat;
     int n,m;
     void dfs(int i,int j){
        if(i<0 || j<0 || i>=3*n || j>=3*m || mat[i][j]) return ;
        mat[i][j]=1;
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i,j-1);
        dfs(i,j+1);
     }
public:
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        m = grid[0].size();
       mat.resize(n * 3, vector<int>(m * 3, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == ' ')
                    continue;
                else if (grid[i][j] == '/') {
                    mat[i * 3][j * 3 + 2] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3] = 1;
                } else {
                    mat[i * 3][j * 3] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
         int ans=0;

        for (int i = 0; i < n * 3; ++i) {
            for (int j = 0; j < m * 3; j++) {
               if(mat[i][j]==0){
                ++ans;
                dfs(i,j);
               }
            }
            // cout << endl;
        }   
       

        return ans;
    }
};