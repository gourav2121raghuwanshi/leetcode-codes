class Solution {
    int n, m;
    // int dp[201][201];
    // int solve(int i,int j,vector<vector<int>>& triangle){
    //     if(i==n) return 0;
    //     if(j>=triangle[i].size()) return 1e7;

    //     if(dp[i][j]!=-1) return dp[i][j];
    //     return dp[i][j] =
    //     triangle[i][j]+min(solve(i+1,j,triangle),solve(i+1,j+1,triangle));
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        m = triangle[n-1].size();
        // memset(dp,0,sizeof(dp));
        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                curr[j] = triangle[i][j] + min(prev[j], prev[j + 1]);
            }
            prev = curr;
        }
        return curr[0];
        // return solve(0,0,triangle);
    }
};