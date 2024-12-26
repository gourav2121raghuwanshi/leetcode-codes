class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (auto& i : edges) {
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != 1e9 && dist[k][j] != 1e9 &&
                        dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int ans = 1e9;
        int node = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (dist[i][j] <= distanceThreshold) {
                    ++cnt;
                }
            }
            if (cnt < ans) {
                ans = cnt;
                node = i;
            }else if (cnt == ans) {
                node = i;
            }
        }
        return node;
    }
};