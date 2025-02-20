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
        if (a == par[a]) return a;
        return par[a] = parent(par[a]);  
    }

    void UnionByRank(int a, int b) {
        int x = parent(a);
        int y = parent(b);
        if (x == y) return;

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
        if (x == y) return;
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
    int minSwapsCouples(vector<int>& row) {
        // Group the couples
        // (0,1) -> group 0
        // (2,3) -> group 1
        // (4,5) -> group 2 .. 
        // by divinding by 2 we can get Their group

        int n=row.size()/2;
        DSU dsu(n);
        for(int i=0;i<row.size();i+=2){
            dsu.UnionByRank(row[i]/2,row[i+1]/2);
        }

        int c=0;
        for(int i=0;i<n;++i){
            if(dsu.parent(i)==i) ++c;
        }
        return n-c;
    }
};