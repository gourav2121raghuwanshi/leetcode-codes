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