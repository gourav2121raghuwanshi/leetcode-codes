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
        unordered_map<string, vector<int>> idx;
        int n = accounts.size();
        DSU dsu(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                idx[accounts[i][j]] .push_back(i);
            }
        }

        for (auto& i : idx) {
            vector<int> v = i.second;
            for (int j = 1; j < v.size(); ++j) {
                dsu.UnionBySize(v[j], v[j - 1]);
            }
        }
        unordered_map<int, int> par;
        for (int i = 0; i < n; i++) {
            par[i] = dsu.parent(i);
        }
        
        // vector<vector<string>>ans;
        unordered_map<int, vector<string>> ans;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                if(ans[par[i]].empty()){
                    ans[par[i]].push_back(accounts[i][0]);
                }
                ans[par[i]].push_back(accounts[i][j]);
            }
        }
        vector<vector<string>> v;
       for(auto&i:ans){
        vector<string>st=i.second;
        string name=st[0];
        set<string>s(st.begin()+1,st.end());
        vector<string>temp;
        temp.push_back(name);
        for(auto&i:s) temp.push_back(i);
        v.push_back(temp);

       }
       return v;
    }
};