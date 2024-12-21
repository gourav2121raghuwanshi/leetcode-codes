class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=nums[0];
        int minSum=nums[0];

        int maxi=nums[0];
        int mini=nums[0];
        int ts=nums[0];
        
        for(int i=1;i<nums.size();i++){
            ts+=nums[i];

            maxSum=max(maxSum+nums[i],nums[i]);
            minSum=min(minSum+nums[i],nums[i]);

            maxi=max(maxi,maxSum);
            mini=min(mini,minSum);
        }
        int cs=ts-mini;
        if(maxi>0) return max(maxi,cs);
        return maxi;

    }
};