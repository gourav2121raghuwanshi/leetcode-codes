class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod=1;
        int l=0;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            prod*=nums[i];
            while(prod>=k && l<i){
                prod/=nums[l++];
            }
            if(prod<k)
            ans+=(i-l+1);
        }
        return ans;
    }
};