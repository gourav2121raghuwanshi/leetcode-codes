class Solution {
     vector<vector<int>>ans;
     void solve(int j,vector<int>& nums,vector<int>& v){
        ans.push_back(v);
        for(int i=j;i<nums.size();++i){
            v.push_back(nums[i]);
            solve(i+1,nums,v);
            v.pop_back();
        }
     }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        solve(0,nums,v);
        
        return ans;
    }
};