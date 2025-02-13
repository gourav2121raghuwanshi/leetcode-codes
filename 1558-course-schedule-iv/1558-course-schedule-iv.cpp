class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>>pre;
        for(auto&i:prerequisites){
            int a=i[0];
            int b=i[1];
            pre[b].insert(a);
        }
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<numCourses;j++){
                if(pre[j].count(i)){
                    pre[j].insert(pre[i].begin(),pre[i].end());
                }
            }
        }
        vector<bool>ans;

        for(auto&i:queries){
            int a=i[0];
            int b=i[1];
            if(pre[b].count(a)){
                ans.push_back(1);
            }else ans.push_back(0);
        }

        return ans;
    }
};