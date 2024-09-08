class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int j=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[j]){
                ans+=(nums[j]*1LL*(i-j));
                j=i;
            }
        }
        return ans+(n-j-1)*1LL*nums[j];
    }
};