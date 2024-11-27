class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int nc=0;
        int mini=1e9;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                ans+=abs(matrix[i][j]);
                if(matrix[i][j]<0) ++nc;
                mini=min(mini,abs(matrix[i][j]));
            }
        }
        if(nc&1) return ans-2*mini;
        return ans;
    }
};