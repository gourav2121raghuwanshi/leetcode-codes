class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int cnt = 1;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto front = q.front();
                q.pop();
                for (auto& j : dir) {
                    int nr = front.first + j.first;
                    int nc = front.second + j.second;
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                        ans[nr][nc] == -1) {
                        ans[nr][nc] = cnt;
                        q.push({nr, nc});
                    }
                }
            }
            ++cnt;
        }
        return ans;
    }
};