class Solution {
   class DSU {
public:
    vector<int> size, par;

    DSU(int n) {
        size.resize(n, 1);
        par.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i; // Each node is its own parent initially
        }
    }

    int parent(int a) {
        if (par[a] != a) {
            par[a] = parent(par[a]); // Path compression
        }
        return par[a];
    }

    void UnionBySize(int a, int b) {
        int x = parent(a);
        int y = parent(b);
        if (x == y) return; // Already in the same set

        // Union by size: attach the smaller tree under the larger tree
        if (size[x] < size[y]) {
            swap(x, y);
        }
        par[y] = x;
        size[x] += size[y];
    }
};

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 1: Union adjacent 1's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {  // Only process land cells
                    for (auto &dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            int idx1 = i * n + j;
                            int idx2 = ni * n + nj;
                            dsu.UnionBySize(idx1, idx2);
                        }
                    }
                }
            }
        }

        // Step 2: Find the largest island by flipping a 0
        int maxIsland = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {  // Consider flipping this zero
                    unordered_set<int> uniqueParents; // To store unique component parents
                    for (auto &dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            uniqueParents.insert(dsu.parent(ni * n + nj));
                        }
                    }
                    
                    // Calculate new island size after flipping
                    int newSize = 1; // The flipped 0 itself
                    for (int parent : uniqueParents) {
                        newSize += dsu.size[parent];
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        // Step 3: If grid is fully 1, return total island size
        if (maxIsland == 0) return n * n;

        return maxIsland;
    }
};
