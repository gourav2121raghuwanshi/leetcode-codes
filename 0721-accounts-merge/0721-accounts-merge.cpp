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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> MailPar;
        int n = accounts.size();
        DSU dsu(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (MailPar.count(accounts[i][j])) {
                    dsu.UnionBySize(i, MailPar[accounts[i][j]]);
                } else {
                    MailPar[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, set<string>> ans;
        for (auto& i : MailPar) {
            ans[dsu.parent(i.second)].insert(i.first);
        }

        vector<vector<string>> v;
        for (auto& i : ans) {
            int idx = i.first;
            set<string> st = i.second;
            string name = accounts[idx][0];
            vector<string> temp;
            temp.push_back(name);
            for (auto& i : st)
                temp.push_back(i);
            v.push_back(temp);
        }
        return v;
    }
};