

class Solution {
     vector<vector<int>>ans;
     void solve(int i,vector<int>& candidates, int target,vector<int>&v){
        if(target==0){
            if(ans.empty() || ans.back()!=v)
            ans.push_back(v);
            return;
        }
        if(i>=candidates.size()) return;
        for(int j=i;j<candidates.size();++j){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(target-candidates[j]>=0){
                v.push_back(candidates[j]);
                solve(j+1,candidates,target-candidates[j],v);
                v.pop_back();
            }
            // solve(j+1,candidates,target,v);
        }

     }
public:
     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        solve(0,candidates,target,v);
        return ans;
    }
};