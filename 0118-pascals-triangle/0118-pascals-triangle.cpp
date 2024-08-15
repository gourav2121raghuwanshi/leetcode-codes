class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        ans[0].resize(1);
        ans[0][0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i].resize(i + 1);
            for (int j = 0; j <= i; ++j) {

                int a = (j<i) ? ans[i - 1][j] : 0;
                int b = (j - 1 >= 0) ? ans[i - 1][j - 1] : 0;
                ans[i][j] = a + b;
            }
        }
        return ans;
    }
};