
class DSU {
    vector<int> rank;
    vector<int> size;

public:
    vector<int> par;

    DSU(int n) {
        rank.resize(n, 0);
        size.resize(n, 1);
        par.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    int parent(int a) {
        if (a == par[a])
            return a;
        return par[a] = parent(par[a]); // Path compression
    }

    void UnionByRank(int a, int b) {
        int x = parent(a);
        int y = parent(b);
        if (x == y)
            return;

        if (rank[x] > rank[y]) {
            par[y] = x;
        } else if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            ++rank[x];
        }
    }

    bool UnionBySize(int a, int b) {
        int x = parent(a);
        int y = parent(b);
        if (x == y)
            return false;
        if (size[x] > size[y]) {
            par[y] = x;
            size[x] += size[y];
        } else {
            par[x] = y;
            size[y] += size[x];
        }
        return true;
    }
};

class Solution {

public:
    int makeConnected(int n, vector<vector<int>>& c) {
        DSU dsu(n);
        int extraCables = 0;

        for (auto& i : c) {
            if (dsu.UnionBySize(i[0], i[1]) == false) {
                ++extraCables;
            }
        }
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.parent(i) == i)
                ++comp;
        }
        if (comp - 1 > extraCables)
            return -1;
        return comp - 1;
    }
};