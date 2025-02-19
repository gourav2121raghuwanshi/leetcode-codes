class Solution {

    class DSU {
    public:
        vector<int> size;

        vector<int> par;

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
            return par[a] = parent(par[a]); // Path compression
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

public:
    int largestComponentSize(vector<int>& nums) {
        unordered_map<int, vector<int>> factors;
        int n = nums.size();
        DSU dsu(n);
        unordered_map<int, int> numberIndex;
        for (int i = 0; i < n; ++i) {
            numberIndex[nums[i]] = i;
            int curr = nums[i];
            for (int j = 1; j * j <= curr; ++j) {
                if (curr % j == 0) {
                    if (j != 1) {
                        factors[j].push_back(i);
                    }
                    int secFec = curr / j;
                    if (secFec != j && secFec != 1) {
                        factors[secFec].push_back(i);
                    }
                }
            }
        }

        for (auto& i : factors) {
            if (i.second.size() > 1) {
                vector<int> temp = i.second;
                int m = temp.size();
                for (int j = 1; j < m; ++j) {
                    dsu.UnionBySize(temp[0], temp[j]);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;++i){
            ans=max(ans,dsu.size[dsu.parent(i)]);
        }
        return ans;
    }
};