class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            bool foundRotten = false;
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& k : dir) {
                    int dx = x + k.first;
                    int dy = y + k.second;
                    if (dx >= 0 && dy >= 0 && dx < n && dy < m &&
                        !vis[dx][dy] && grid[dx][dy] == 1) {
                        foundRotten = true;
                        grid[dx][dy] = 2;

                        vis[dx][dy] = true;
                        q.push({dx, dy});
                    }
                }
            }
            if (foundRotten == false)
                break;
            ++ans;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};