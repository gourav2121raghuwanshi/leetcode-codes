class Solution {
    using p = pair<int, pair<int, int>>;

public:
    int trapRainWater(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();
        priority_queue<p, vector<p>, greater<p>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.push({height[i][j], {i, j}});
                }
            }
        }
        int ans = 0;
        int row[] = {0, 0, 1, -1};
        int col[] = {1, -1, 0, 0};
        vector<vector<int>> vis(n, vector<int>(m, false));
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int h = front.first;
            int x = front.second.first;
            int y = front.second.second;
            if (vis[x][y])
                continue;
            ans += h - height[x][y];
            vis[x][y] = 1;
            for (int k = 0; k < 4; ++k) {
                int dr = row[k] + x;
                int dc = col[k] + y;
                if (dr < n && dc < m && dr >= 0 && dc >= 0 && !vis[dr][dc]) {
                    pq.push({max(h, height[dr][dc]), {dr, dc}});
                }
            }
        }
        return ans;
    }
};