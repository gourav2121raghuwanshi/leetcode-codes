class comp {
public:
    bool operator()(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
};
class Solution {
    int n, m;
    void dfs(int i, int j, vector<vector<int>>& isInfected,
             vector<vector<bool>>& vis, set<pair<int, int>>& damage,
             int& size) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            isInfected[i][j] == -1)
            return;
        if (isInfected[i][j] == 0) {
            damage.insert({i, j});
            ++size;
            return;
        }

        vis[i][j] = 1;

        dfs(i - 1, j, isInfected, vis, damage, size);
        dfs(i + 1, j, isInfected, vis, damage, size);
        dfs(i, j - 1, isInfected, vis, damage, size);
        dfs(i, j + 1, isInfected, vis, damage, size);
    }

    void dfs2(int i, int j, vector<vector<int>>& isInfected) {
        if (i < 0 || j < 0 || i >= n || j >= m || isInfected[i][j] == 0 ||
            isInfected[i][j] == -1)
            return;
        isInfected[i][j] = -1;
        dfs2(i - 1, j, isInfected);
        dfs2(i + 1, j, isInfected);
        dfs2(i, j - 1, isInfected);
        dfs2(i, j + 1, isInfected);
    }
    void markInfected_dfs(int i, int j, vector<vector<int>>& isInfected,
                          vector<vector<bool>>& vis) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            isInfected[i][j] == -1)
            return;
        vis[i][j] = 1;
        if (isInfected[i][j] == 0) {
            isInfected[i][j] = 1;
            return;
        }
        markInfected_dfs(i - 1, j, isInfected, vis);
        markInfected_dfs(i + 1, j, isInfected, vis);
        markInfected_dfs(i, j - 1, isInfected, vis);
        markInfected_dfs(i, j + 1, isInfected, vis);
    }

public:
    int containVirus(vector<vector<int>>& isInfected) {
        n = isInfected.size();
        m = isInfected[0].size();
        int ans = 0;
        while (true) {
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            priority_queue<vector<int>> pq;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!vis[i][j] && isInfected[i][j] == 1) {
                        set<pair<int, int>> damage;
                        int ansSize = 0;
                        dfs(i, j, isInfected, vis, damage, ansSize);
                        pq.push({(int)damage.size(), (int)ansSize, i, j});
                    }
                }
            }
            if (pq.empty())
                break;
            auto front = pq.top();
            int x = front[2];
            int y = front[3];
            ans += front[1];
            dfs2(x, y, isInfected);
            vis.assign(n, vector<bool>(m, false));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (isInfected[i][j] == 1 && !vis[i][j]) {
                        markInfected_dfs(i, j, isInfected, vis);
                    }
                }
            }
        }
        return ans;
    }
};
