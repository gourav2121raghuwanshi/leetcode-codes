class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms=nums[0];
        int cs=nums[0];
        int n=nums.size();
        for(int i=1;i<n;++i){
            cs=max(cs+nums[i],nums[i]);
            ms=max(cs,ms);
        }
        return ms;
    }
};