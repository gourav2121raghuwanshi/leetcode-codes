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
            dsu.UnionBySize(i, maskIdx[currMask]);

            for (auto& j : words[i]) {
                // First we remove a character
                int maskByRemovingJthChar = currMask ^ (1 << (j - 'a'));
                if (maskIdx.count(maskByRemovingJthChar)) {
                    dsu.UnionBySize(i, maskIdx[maskByRemovingJthChar]);
                }
                for (int k = 0; k < 26; ++k) {
                    if (k == j - 'a')
                        continue;
                    // Now add some other Character
                    int maskByAddingChar = maskByRemovingJthChar | (1 << k);
                    if (maskIdx.count(maskByAddingChar)) {
                        dsu.UnionBySize(i, maskIdx[maskByAddingChar]);
                    }
                }
            }
        }
        int msz = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            int par=dsu.parent(i);
            st.insert(par);
            msz = max(msz, dsu.size[par]);
        }
        return {(int)st.size(), msz};
    }
};