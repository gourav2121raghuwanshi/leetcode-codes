class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int s=1;
        int e=0;
        int maxi=nums[0];
        for(int i=1;i<n;++i){
            if(maxi>nums[i]){
                e=i;
            }else maxi=nums[i];
        }
        int mini=nums[n-1];
        for(int i=n-2;i>=0;--i){
            if(mini<nums[i]){
                s=i;
            }else mini=nums[i];
        }
        return e-s+1;
    }
};