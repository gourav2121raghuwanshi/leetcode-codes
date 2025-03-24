class DSU {
public:
    vector<int> rank;
    vector<int> par;
    DSU(int n) {
        rank.resize(n + 1, 0);
        par.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            par[i] = i;
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
            rank[x]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        int candidate1=-1;
        int candidate2=-1;

        vector<int>in(n+1,-1);
        for(int i=0;i<n;++i){
            int a=edges[i][0];
            int b=edges[i][1];
            if(in[b]==-1){
                in[b]=i;
            }else{
                candidate1=i;
                candidate2=in[b];
            }
        }
        // for(auto&i:in) cout<<i<<" ";
        // cout<<endl;
        // cout<<candidate1<<" , "<<candidate2<<endl;
        for(int i=0;i<n;++i){
            if(i==candidate1) continue;
            int a=edges[i][0];
            int b=edges[i][1];
            if(dsu.parent(a)==dsu.parent(b)){
                if(candidate1==-1) return edges[i] ;
                return edges[candidate2];
            }else{
                dsu.UnionByRank(a,b);
            }
        }
        return edges[candidate1];
        // return {};
    }
};