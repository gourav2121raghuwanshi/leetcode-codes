class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        queue<pair<int, int>> pq;
        int c = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    pq.push({i, j});
                }
            }
        }
        if(pq.size()==n*m || pq.size()==0) return -1;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            int size = pq.size();
            while (size--) {
                auto front = pq.front();
                pq.pop();
                for (auto& i : dir) {
                    int nx = front.first + i.first;
                    int ny = front.second + i.second;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                        dist[nx][ny] > dist[front.first][front.second] + 1) {
                        dist[nx][ny] = dist[front.first][front.second] + 1;
                        pq.push({nx, ny});
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                if(dist[i][j])
                ans = max(ans, dist[i][j]);
            }
        }
        return ans==0?-1:ans;
    }
};