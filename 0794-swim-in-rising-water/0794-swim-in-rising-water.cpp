class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[0][0] = 1;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int dis = front[0];
            int x = front[1];
            int y = front[2];
            if (x == n - 1 && y == m - 1)
                return dis;

            for (auto& i : dir) {
                int dx = x + i.first;
                int dy = y + i.second;
                if (dx >= 0 && dy >= 0 && dx < n && dy < m) {
                    if (vis[dx][dy])
                        continue;
                    vis[dx][dy] = 1;
                    pq.push({max(dis, grid[dx][dy]), dx, dy});
                }
            }
        }
        return -1;
    }
};