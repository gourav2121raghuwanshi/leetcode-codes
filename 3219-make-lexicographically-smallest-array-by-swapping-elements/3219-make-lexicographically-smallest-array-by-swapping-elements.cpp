class Solution {
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
            return par[a] = parent(par[a]);
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

            if (rank[x] > rank[y]) {
                par[y] = x;
                size[x] += size[y];
            } else {
                par[y] = x;
                size[y] += size[x];
            }
        }
    };

public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> a;
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            a.push_back({nums[i], i});
        }
        sort(a.begin(), a.end());

        unordered_map<int, vector<int>> idxs;
        for (int i = 0; i < nums.size(); ++i) {
            idxs[i].push_back(nums[i]);
        }

        DSU dsu(n);
        int i = 0;
        while (i < a.size()) {
            int j = i + 1;
            cout << a[i].first << " - ";
            while (j < a.size() && a[j].first - a[i].first <= limit) {
                cout << a[j].first << " - ";
                dsu.UnionByRank(a[j].second, a[i].second);
                ++j;
            }
            if (j > i + 1)
                i = j - 1;
            else
                i = j;
        }

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[dsu.parent(i)].push_back(nums[i]);
        }
        for (auto& i : mp) {
            sort(i.second.rbegin(), i.second.rend());
        }

        vector<int> ans(nums.size());

        for (int i = 0; i < n; i++) {
            ans[i] = mp[dsu.parent(i)].back();
            mp[dsu.parent(i)].pop_back();
        }

        return ans;
    }
};