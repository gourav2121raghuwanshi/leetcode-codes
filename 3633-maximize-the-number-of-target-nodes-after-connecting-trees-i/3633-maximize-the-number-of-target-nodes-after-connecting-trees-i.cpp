class Solution {
    unordered_map<int,vector<int>>adj1,adj2;

    int NodesAtDist_k_1(int node,int k){
        unordered_map<int,bool>vis;
        queue<int>q;
        int cnt=0;
        q.push(node);
        vis[node]=true;
        int d=0;
        while(!q.empty() && d<=k){
            int size=q.size();
            while(size--){
                int top=q.front(); q.pop();
                ++cnt;
                for(auto&j:adj2[top]){
                    if(!vis[j]){
                        vis[j]=1;
                        q.push(j);
                    }
                }
            }
            ++d;
        }

        return cnt;
    }
        int NodesAtDist_k(int node,int k){
        unordered_map<int,bool>vis;
        queue<int>q;
        int cnt=0;
        q.push(node);
        vis[node]=true;
        int d=0;
        while(!q.empty() && d<=k){
            int size=q.size();
            while(size--){
                int top=q.front(); q.pop();
                ++cnt;
                for(auto&j:adj1[top]){
                    if(!vis[j]){
                        vis[j]=1;
                        q.push(j);
                    }
                }
            }
            ++d;
        }

        return cnt;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        for(auto&i:edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
       
        }
        for(auto&i:edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }

 int maxNodesAtDist_k_1_in_edges2=0;

        int m=edges2.size();
        for(int i=0;i<=m;i++){
        maxNodesAtDist_k_1_in_edges2=max(NodesAtDist_k_1(i,k-1),maxNodesAtDist_k_1_in_edges2);
        }
       vector<int>ans;
        int n=edges1.size();
        for(int i=0;i<=n;i++){
        int val = NodesAtDist_k(i,k);
        ans.push_back(val+maxNodesAtDist_k_1_in_edges2);
        }
        return ans;
    }
};