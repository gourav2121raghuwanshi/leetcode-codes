class DSU {
public:
    vector<int> par;
    vector<int> size;
    DSU(int n) {
        size.resize(n, 1);
        par.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }
    int parent(int a) {
        if (a == par[a])
            return a;
        return par[a] = parent(par[a]);
    }

    void UnionBySize(int a, int b) {
        int x = parent(a);
        int y = parent(b);
        if (x == y)
            return;
        if (size[x] > size[y]) {
            par[y] = x;
            size[x] += size[y];
        } else {
            par[x] = y;
            size[y] += size[x];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n * m + 1);
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {

                if (grid[i][j]) {
                    int node1 = i * m + j;
                    for (auto& k : dir) {
                        int dx = k.first + i;
                        int dy = k.second + j;
                        if (dx >= 0 && dy >= 0 && dx < n && dy < m &&
                            grid[dx][dy]) {
                            int node2 = dx * m + dy;
                            dsu.UnionBySize(node1, node2);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    int node1 = i * m + j;
                    ans = max(ans, dsu.size[dsu.parent(node1)]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> pars;
                    for (auto& k : dir) {
                        int dx = k.first + i;
                        int dy = k.second + j;
                        if (dx >= 0 && dy >= 0 && dx < n && dy < m &&
                            grid[dx][dy] == 1) {
                            int node2 = dx * m + dy;
                            pars.insert(dsu.parent(node2));
                        }
                    }
                    int size = 1; // include 0
                    for (auto& i : pars)
                        size += dsu.size[i];
                    ans = max(ans, size);
                }
            }
        }

        return ans;
    }
};