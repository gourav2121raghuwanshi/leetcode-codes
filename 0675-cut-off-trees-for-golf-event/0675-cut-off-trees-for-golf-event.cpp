class Solution {
    int n, m;
    int bfs(int startx, int starty, int endx, int endy,
            vector<vector<int>>& forest) {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[startx][starty] = true;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {startx, starty}});
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto front = q.front();
            int x = front.second.first;
            int y = front.second.second;
            int steps = front.first;
            q.pop();
            if (x == endx && y == endy)
                return steps;
            for (auto& k : dir) {
                int nx = x + k.first;
                int ny = y + k.second;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] &&
                    forest[nx][ny] > 0) {
                    q.push({steps + 1, {nx, ny}});
                    vis[nx][ny] = true;
                }
            }
        }
        return -1;
    }

public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, pair<int, int>>> v;
        n = forest.size();
        m = forest[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (forest[i][j] > 1)
                    v.push_back({forest[i][j], {i, j}});
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (i == 0) {
                int startx = 0;
                int starty = 0;
                int endx = v[i].second.first;
                int endy = v[i].second.second;
                int val = bfs(startx, starty, endx, endy, forest);
                if (val == -1)
                    return -1;
                ans += val;
            } else {
                int startx = v[i - 1].second.first;
                int starty = v[i - 1].second.second;
                int endx = v[i].second.first;
                int endy = v[i].second.second;
                int val = bfs(startx, starty, endx, endy, forest);
                if (val == -1)
                    return -1;
                ans += val;
            }
        }
        return ans;
    }
};