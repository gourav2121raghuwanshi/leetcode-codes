class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>sum(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                sum[i][j]=mat[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
         vector<vector<int>> ans(n, vector<int>(m, 0));
      
           for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
            int x0=max(0,i-k);
            int x1=min(n-1,i+k);
            int y0=max(0,j-k);
            int y1=min(m-1,j+k);

            ans[i][j]=sum[x1+1][y1+1]-sum[x1+1][y0]-sum[x0][y1+1]+sum[x0][y0];
            }
        }
        return ans;
    }
};