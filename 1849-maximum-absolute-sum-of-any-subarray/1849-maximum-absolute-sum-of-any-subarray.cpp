class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum=nums[0];
        int maxi=nums[0];
        int minsum=nums[0];
        int mini=nums[0];
        for(int i=1;i<nums.size();++i){
            maxi=max(nums[i],maxi+nums[i]);
            maxsum=max(maxsum,maxi);
            mini=min(nums[i],mini+nums[i]);
            minsum=min(minsum,mini);
        }
        return max(maxsum,abs(minsum));
    }
};