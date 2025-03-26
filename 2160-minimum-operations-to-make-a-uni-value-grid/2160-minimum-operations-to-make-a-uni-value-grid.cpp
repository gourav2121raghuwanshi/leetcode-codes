class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // 1 2 3 5
        // 1,1,2
        vector<int> v;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        n = v.size();
        for (int i = 1; i < n; ++i) {
            if ((v[i] - v[i - 1]) % x != 0)
                return -1;
        }
        int ans=0;
        int median=v[n/2];
        for(auto&i:v){
            ans+=abs(i-median)/x;
        }
        
        return ans;
    }
};