class Solution {
      class DSU {
        vector<int> rank;
        vector<int> size;

    public:
        vector<int> par;
        DSU(int n) {
            rank.resize(n, 0);
            // size.resize(n, 1);
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
    };
    unordered_map<int,vector<int>>adj;
    unordered_set<int>st;
    char getMin(int i,string s){
        if(st.count(i)) return s[i];
          char mini=s[i];
          st.insert(i);
          for(auto&j:adj[i]){
            mini=min(mini,getMin(j,s));
          }
          return mini;
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string ans;
        DSU dsu((int)1e5+1);

        for(auto&i:pairs){
            dsu.UnionByRank(i[1],i[0]);
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>>mp;
        for(int i=0;i<s.size();++i){
            mp[dsu.parent(i)].push(s[i]);
        }
        for(int i=0;i<s.size();++i){
            ans.push_back(mp[dsu.parent(i)].top());
            mp[dsu.parent(i)].pop();
        }

        return ans;
    }
};