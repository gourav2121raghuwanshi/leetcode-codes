class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans = 0;
        for (auto& i : grid) {
            sort(i.rbegin(), i.rend());
        }
        priority_queue<int> pq;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            int lim = limits[i];
            for (int j = 0; j < lim; ++j) {
                pq.push(grid[i][j]);
            }
        }
        while (k-- && !pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};