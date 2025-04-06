class Solution {
     vector<vector<int>>ans;
     void solve(int i,vector<int>& can, int t,vector<int>&v){
        if(t==0){
            ans.push_back(v);
            return;
        }
        if(i>=can.size()) return;
        if(can[i]<=t){
            v.push_back(can[i]);
            solve(i,can,t-can[i],v);
            v.pop_back();
        }
        solve(i+1,can,t,v);
     }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
       vector<int>v;
       solve(0,can,t,v);
       return ans;
    }
};