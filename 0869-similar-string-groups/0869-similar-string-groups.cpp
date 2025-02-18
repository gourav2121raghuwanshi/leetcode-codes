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
        return par[a] = parent(par[a]);  // Path compression
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
    int numSimilarGroups(vector<string>& strs) {
        int ans=0;

        int n=strs.size();
        DSU dsu(n);
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int c=0;
                for(int k=0;k<strs[i].size();++k){
                    if(strs[i][k]!=strs[j][k]){
                        ++c;
                    }
                }
                if(c==2 || c==0) {
                    dsu.UnionByRank(i,j);
                }
            }
        }
        unordered_set<int>st;
        for(int i=0;i<n;++i){
            st.insert(dsu.parent(i));
        }
        return st.size(); 
    }
};