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
        vector<int>adj(n,0);
        for(auto&i:edges){
            int a=i[0];
            int b=i[1];
            adj[a]++;
            adj[b]++;
            dsu.unionByRank(a,b);   
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[dsu.parent(i)]++;
        }
        int ans=0;
        for(auto&i:mp){
            int root=i.first;
            int compSize=i.second;
            bool f=true;
            for(int i=0;i<n;++i){
                if(dsu.parent(i)==root && adj[i]!=compSize-1){
                    f=false;
                    break;
                }
            }
            if(f)++ans;
        }
       
        return ans;
    }
};