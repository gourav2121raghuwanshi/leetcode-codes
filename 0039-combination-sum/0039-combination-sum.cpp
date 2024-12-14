class Solution {
     vector<vector<int>>ans;
     void solve(int i,vector<int>& candidates, int target,vector<int>&v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i>=candidates.size()) return;
        if(target-candidates[i]>=0){
            v.push_back(candidates[i]);
            solve(i,candidates,target-candidates[i],v);
            v.pop_back();
        }
            solve(i+1,candidates,target,v);
     }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>v;
        solve(0,candidates,target,v);
        return ans;
    }
};