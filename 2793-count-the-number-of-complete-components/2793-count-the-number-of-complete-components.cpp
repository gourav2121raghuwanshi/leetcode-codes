class DSU{
    public:
    vector<int>rank;
    vector<int>par;
    DSU(int n){
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;++i) par[i]=i;
    }
    int parent(int a){
        if(a==par[a]) return a;
        return par[a]=parent(par[a]);
    }
    void unionByRank(int a,int b){
        int x=parent(a);
        int y=parent(b);
        if(x==y) return;
        if(rank[x]>rank[y]){
            par[y]=x;
        }else if(rank[x]<rank[y]){
            par[x]=y;
        }else{
             par[x]=y;
             rank[y]++;
        }
    }

};
class Solution {
    

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int,vector<int>>adj;
        for(auto&i:edges){
            int a=i[0];
            int b=i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(dsu.parent(a)!=dsu.parent(b)){
                    dsu.unionByRank(a,b);
            }
        }
        unordered_map<int,unordered_set<int>>mp;
        unordered_map<int,bool>chk;
        for(int i=0;i<n;i++){
            mp[dsu.parent(i)].insert(i);
            chk[dsu.parent(i)]=true;
        }
        int total=mp.size();
         
       
        for(int i=0;i<n;i++){
            int val=mp[dsu.parent(i)].size()-1;
            if(adj[i].size()!=val){
                chk[dsu.parent(i)]=false;
            }
        }
        int ans=0;
        for(auto&i:chk){
            if(i.second) ++ans;
        }
        return ans;
    }
};