class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e7));
       
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        for (auto& i : edges) {
            int a = i[0];
            int b = i[1];
            int w = i[2];
            dist[a][b] = w;
            dist[b][a] = w;
        }
        

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != 1e7 && dist[k][j] != 1e7 &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int mini = 1e9;
        int ans = -1;

        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i - 1][j] <= distanceThreshold)
                    ++cnt;
            }
            if (cnt < mini) {
                mini = cnt;
                ans = i - 1;
            } else if (cnt == mini)
                ans = i - 1;
        }

        return ans;
    }
};