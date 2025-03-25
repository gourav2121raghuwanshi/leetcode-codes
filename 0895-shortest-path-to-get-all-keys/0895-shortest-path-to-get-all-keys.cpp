class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int totalKeys = 0, startX, startY;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c = grid[i][j];
                if (c == '@') {
                    startX = i; 
                    startY = j;
                }
                if (c >= 'a' && c <= 'z') {
                    totalKeys++;
                }
            }
        }
        int target = (1 << totalKeys) - 1;
        // visited[x][y][keys] : whether cell (x,y) has been visited with the keys bitmask 'keys'
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(1 << totalKeys, false)));
        queue<vector<int>> q; // {steps, x, y, keys}
        q.push({0, startX, startY, 0});
        visited[startX][startY][0] = true;
        
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int steps = cur[0], x = cur[1], y = cur[2], keys = cur[3];
            if (keys == target)
                return steps;
            
            for (auto& d : directions) {
                int nx = x + d.first, ny = y + d.second;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                char cell = grid[nx][ny];
                if (cell == '#')
                    continue;
                int newKeys = keys;
                if (cell >= 'a' && cell <= 'z') {
                    newKeys |= (1 << (cell - 'a'));
                }
                if (cell >= 'A' && cell <= 'Z') {
                    // Only proceed if we have the corresponding key.
                    if (!(newKeys & (1 << (cell - 'A'))))
                        continue;
                }
                if (!visited[nx][ny][newKeys]) {
                    visited[nx][ny][newKeys] = true;
                    q.push({steps + 1, nx, ny, newKeys});
                }
            }
        }
        return -1;
    }
};
