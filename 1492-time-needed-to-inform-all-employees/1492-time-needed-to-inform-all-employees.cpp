class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>adj;
        int root=-1;
        for(int i=0;i<n;++i){
            if(manager[i]==-1){
                root=i;
            }else{
                adj[manager[i]].push_back(i);
            }
        }
        int ans=0;
        queue<pair<int,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto front=q.front(); q.pop();
                int node=front.first;
                int cost=front.second;
                ans=max(ans,cost);
                for(auto&j:adj[node]){
                    q.push({j,cost+informTime[node]});
                }
            }
        }
        return ans;

    }
};