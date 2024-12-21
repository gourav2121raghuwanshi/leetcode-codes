class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        for(auto&i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>mark(n+1,-1);
        for(int i=1;i<=n;++i){
            if(mark[i]!=-1) continue;
            mark[i]=0;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                auto front=q.front(); q.pop();
                for(auto&j:adj[front]){
                    if(mark[j]==-1){
                        mark[j]=1-mark[front];
                        q.push(j);
                    }
                    if(mark[j]==mark[front]) return false;
                    else {
                       continue;
                    }
                }
            }
        }
        return true;
    }
};