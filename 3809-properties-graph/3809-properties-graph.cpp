
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
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; ++j) {
                if(dsu.parent(i)==dsu.parent(j)) continue;
                unordered_set<int> a(properties[i].begin(),
                                     properties[i].end());
                unordered_set<int> b(properties[j].begin(),
                                     properties[j].end());
                int c = 0;
                for(auto&kk:a){
                    if(b.count(kk)) ++c;
                }
                if(c>=k){
                    dsu.UnionByRank(i,j);
                }
            }
        }
        unordered_set<int>ans;
        for(int i=0;i<n;i++){
            ans.insert(dsu.parent(i));
        }
        return ans.size();
    }
};