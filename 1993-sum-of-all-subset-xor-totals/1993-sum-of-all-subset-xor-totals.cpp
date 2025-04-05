class Solution {
    int ans=0;
    void solve(int i,int xo,vector<int>& nums){
        if(i>=nums.size()){
            ans+=xo;
            return;
        }
        solve(i+1,xo^nums[i],nums);
        solve(i+1,xo,nums);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        solve(0,0,nums);
        return ans;
    }
};