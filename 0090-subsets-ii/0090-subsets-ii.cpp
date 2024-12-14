class Solution {
     vector<vector<int>>ans;
     void solve(int i,vector<int>&nums,vector<int>&v){
        ans.push_back(v);

        for(int j=i;j<nums.size();++j){
            if(j>i && nums[j]==nums[j-1]) continue;
            v.push_back(nums[j]);
            solve(j+1,nums,v);
            v.pop_back();
        }

     }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        solve(0,nums,v);

        return ans; 
    }
};