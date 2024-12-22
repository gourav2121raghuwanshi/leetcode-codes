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
            int x=parent(a);
            int y=parent(b);
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
            int x=parent(a);
            int y=parent(b);
           
            if (rank[x] > rank[y]) {
                par[y] = x;
                size[x]+=size[y];
            } else {
                par[y] = x;
               size[y]+=size[x];
            }
        }
    };
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto&i:stones){
            maxRow=max(maxRow,i[0]);
            maxCol=max(maxCol,i[1]);
        }
        DSU dsu(maxRow+maxCol+2);
        for(auto&i:stones){
           dsu.UnionByRank(i[0],i[1]+maxRow+1);
        }
        unordered_set<int>st;
        for(auto&i:stones){
           st.insert(dsu.parent(i[0]));
           st.insert(dsu.parent(i[1]+maxRow+1));
        }
        return stones.size()-st.size();
    }
};