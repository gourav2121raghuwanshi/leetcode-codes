class Solution {
public:



	void makeset(int n, vector<int>& par) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int parent(int a, vector<int>& par) {
    if (a == par[a])
        return a;
    return par[a] = parent(par[a], par); 
}

void Union(int a, int b, vector<int>& par, vector<int>& rank) {
    int p1 = parent(a, par);
    int p2 = parent(b, par);
    if (p1 != p2) {
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
        } else if (rank[p2] > rank[p1]) {
            par[p1] = p2;
        } else {
            par[p1] = p2;
            rank[p2]++;
        }
    }
}
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
     {
       
     
        int n = edges.size();
         vector<int> par(n);
         vector<int> rank(n,0);
         vector<int>ans;
          makeset(n,par);
        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            if(parent(a-1,par)!=parent(b-1,par)){
                Union(a-1,b-1,par,rank);
            }
            else{
        ans.push_back(a-1);
        ans.push_back(b-1);
            }
        }

      
        
    if(ans.empty()) return {};
        return {ans[ans.size()-2]+1,ans[ans.size()-1]+1};
    }
};
