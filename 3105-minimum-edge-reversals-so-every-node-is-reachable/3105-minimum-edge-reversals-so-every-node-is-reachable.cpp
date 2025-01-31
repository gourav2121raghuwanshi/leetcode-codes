class Solution {
    // video : https://www.youtube.com/watch?v=L8GJkBbAj8E
     vector<vector<pair<int,int>>>adj;
     vector<int>depth;
     vector<int>edge_reverse_count;
     void dfs(int node,int c,int d,int par,int &ans_for_0){
        depth[node]=d;
        edge_reverse_count[node]=c;
        for(auto&i:adj[node]){
            if(i.first!=par){
                ans_for_0+=i.second;
                dfs(i.first,c+i.second,d+1,node,ans_for_0);
            }
        }
     }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // a->b : adj[a]->(b,0) and adj[b]->(a,1)
        depth.resize(n);
        adj.resize(n);
        edge_reverse_count.resize(n);
        for(auto&i:edges){
            int a=i[0];
            int b=i[1];
            adj[a].push_back({b,0});
            adj[b].push_back({a,1});
        }
        int c=0;
        int d=0;
        int ans_for_0=0;
        dfs(0,c,d,-1,ans_for_0);
        vector<int>ans(n);
        ans[0]=ans_for_0;
        for(int i=1;i<n;i++){
            ans[i]=ans_for_0-edge_reverse_count[i]+(depth[i]-edge_reverse_count[i]);
        }

        for(int i=0;i<n;i++){
            cout<<depth[i]<<" , "<<edge_reverse_count[i]<<endl;
        }
        return ans;
    }
};