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
        // isInfected[i][j] = -1;
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
            cout << "size =>" << front[1] << endl;
            ans += front[1];
            dfs2(x, y, isInfected);
            // vis.resize(n, vector<bool>(m, false));
            vis.assign(n, vector<bool>(m, false));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (isInfected[i][j] == 1 && !vis[i][j]) {
                        cout << "goes " << i << " " << j << endl;
                        markInfected_dfs(i, j, isInfected, vis);
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << isInfected[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        return ans;
    }
};
/*
class cluster {
public:
    int wc = 0;               // wall count
    set<pair<int, int>> con;  // contaminedted (x,y) of current cluster
    set<pair<int, int>> ucon; // un-contaminedted (x,y) of current cluster
};

class comp {
public:
    bool operator()(const cluster& a,const cluster& b) {
        return a.ucon.size() < b.ucon.size();
    }
};

class Solution {
    int n, m;
    void dfs(int i, int j, vector<vector<int>>& isInfected,
             vector<vector<bool>>& vis, cluster& c) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j]==true ||
            isInfected[i][j] == -1)
            return;

        if (isInfected[i][j] == 0) {
            c.ucon.insert({i, j});
            ++c.wc;
            return;
        }
        vis[i][j] = true;
        c.con.insert({i, j});
        dfs(i - 1, j, isInfected, vis, c);
        dfs(i + 1, j, isInfected, vis, c);
        dfs(i, j - 1, isInfected, vis, c);
        dfs(i, j + 1, isInfected, vis, c);
    }


public:
    int containVirus(vector<vector<int>>& isInfected) {
        n = isInfected.size();
        m = isInfected[0].size();
        int ans = 0;
        while (true) {
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            priority_queue<cluster, vector<cluster>, comp> pq;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!vis[i][j] && isInfected[i][j] == 1) {
                        cluster c;
                        dfs(i, j, isInfected, vis, c);
                        pq.push(c);
                    }
                }
            }

            if (pq.empty())
                break;
            cluster top = pq.top();
            pq.pop();
            ans += top.wc;
            for (auto& i : top.con) {
                int x = i.first;
                int y = i.second;
                isInfected[x][y] = -1;
            }
            while (!pq.empty()) {
                top = pq.top();
                pq.pop();
                for (auto& i : top.ucon) {
                    int x = i.first;
                    int y = i.second;
                    isInfected[x][y] = 1;
                }
            }
        }
        return ans;
    }
};
*/