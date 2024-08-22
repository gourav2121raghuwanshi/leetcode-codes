class Solution {
    class DSU {
        vector<int> rank;
        vector<int> parent;

    public:
        DSU(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        int findParent(int a) {
            if (a == parent[a])
                return a;
            return parent[a] = findParent(parent[a]);
        }
        void Union(int a, int b) {
            int x = findParent(a);
            int y = findParent(b);
            if (x == y)
                return;
            if (rank[x] > rank[y]) {
                parent[y] = x;
            } else if (rank[y] > rank[x]) {
                parent[x] = y;
            } else {
                parent[y] = x;
                rank[x]++;
            }
        }
    };

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        DSU prov(n);
       for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) { 
                if (isConnected[i][j]) {
                    prov.Union(i, j);
                }
            }
        }

        unordered_set<int> uniqueParents;
        for (int i = 0; i < n; i++) {
            uniqueParents.insert(prov.findParent(i));
        }
        return uniqueParents.size();
    }
};