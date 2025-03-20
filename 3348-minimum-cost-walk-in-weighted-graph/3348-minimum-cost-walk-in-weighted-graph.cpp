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
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        // make all componests
        // for two nodes in same component
        // ans = and of all weights as we can visit the same edge or vertex more than once.
        // and reduces value always so do and of all

        vector<int>ans;
        for(auto&i:edges){
            int a=i[0];
            int b=i[1];
            int w=i[2];
            if(dsu.parent(a)!=dsu.parent(b)){
                dsu.UnionByRank(a,b);
            }
        }
        unordered_map<int,unordered_set<int>>mp;
        for(auto&i:edges){
            mp[dsu.parent(i[0])].insert(i[2]);
        }
        unordered_map<int,int>parentValue;
        for(auto&i:mp){
            int par=i.first;
            int aNd=*i.second.begin();
            for(auto&j:i.second){
                aNd&=j;
            }
            parentValue[par]=aNd;
        }
        for(auto&i:query){
            int a=i[0];
            int b=i[1];
            if(dsu.parent(a)!=dsu.parent(b)){
                ans.push_back(-1);
            }else{
                ans.push_back(parentValue[dsu.parent(a)]);
            }
        }
        return ans;
    }
};