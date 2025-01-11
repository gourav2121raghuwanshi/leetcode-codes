class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, 
    vector<vector<int>>& redEdges, 
    vector<vector<int>>& blueEdges) {
        // vector<int>ans;//
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto&i:redEdges){
            int a=i[0];
            int b=i[1];
            adj[a].push_back({b,1});
        }
         for(auto&i:blueEdges){
            int a=i[0];
            int b=i[1];
            adj[a].push_back({b,0});
        }
        queue<pair<int,int>>q;
        q.push({0,-1});
        vector<int>ans(n,1e9);
        set<pair<int,int>>vis;
    
        ans[0]=0;
        int dist=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--){
                auto front=q.front(); q.pop();
                int color=front.second;
                int node=front.first;
                if(front.first==0){
                    for(auto&i:adj[0]){
                        int node=i.first;
                        int color=i.second;
                        if(!vis.count({node,color})){
                            ans[node]=1;
                            q.push({node,color});
                            vis.insert({node,color});
                        }
                    }
                }else{
                    for(auto&i:adj[node]){
                        if(i.second!=color && !vis.count({i.first,i.second})){
                            ans[i.first]=min(ans[i.first],dist);
                            q.push({i.first,i.second});
                            vis.insert({i.first,i.second});
                        }
                    }
                }
            }
            ++dist;
        }
        for(auto&i:ans){
            if(i==1e9) i=-1;
        }
        ans[0]=0;
        return ans;
    }
};