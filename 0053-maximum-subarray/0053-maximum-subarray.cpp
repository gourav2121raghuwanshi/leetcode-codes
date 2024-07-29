class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=nums[0];
        int i;
        int n=nums.size();
        for( i=0;i<n;++i){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<=0) sum=0;
        }
        return maxi;
    }
};