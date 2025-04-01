class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           vector<int>ans;
         
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int>in(numCourses,0);
        for(auto&i:prerequisites){
             ++in[i[0]];
             adj[i[1]].push_back(i[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;++i){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto&j:adj[t]){
                --in[j];
                if(in[j]==0) q.push(j);
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};