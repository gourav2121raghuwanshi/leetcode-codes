class Solution {

    class DSU {
    public:
        vector<int> rank;
        vector<int> size;

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

    int getMask(string s) {
        int mask = 0;
        for (auto& i : s) {
            mask = mask | (1 << (i - 'a'));
        }
        return mask;
    }

public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        DSU dsu(n);
        unordered_map<int, int> maskIdx;
        vector<int> mask(n);
        for (int i = 0; i < n; ++i) {
            mask[i] = getMask(words[i]);
            maskIdx[mask[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            int currMask = mask[i];
            if (maskIdx.count(currMask)) {
                dsu.UnionBySize(i, maskIdx[currMask]);
            }
            for (auto& j : words[i]) {
                int maskByRemovingJthChar = currMask ^ (1 << (j - 'a'));
                if (maskIdx.count(maskByRemovingJthChar)) {
                    dsu.UnionBySize(i, maskIdx[maskByRemovingJthChar]);
                }
                for (int k = 0; k < 26; ++k) {
                    if (k == j - 'a')
                        continue;
                    int maskByReplacing = maskByRemovingJthChar | (1 << k);
                    if (maskIdx.count(maskByReplacing)) {
                        dsu.UnionBySize(i, maskIdx[maskByReplacing]);
                    }
                }
            }
        }
        int msz = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(dsu.parent(i));
            msz = max(msz, dsu.size[dsu.parent(i)]);
        }
        return {(int)st.size(), msz};
    }
};