class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;

        for(int i=0;i<nums.size();++i){
            int mini=nums[i];
            int maxi=nums[i];
            for(int j=i+1;j<nums.size();++j){
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);
                ans+=1LL*(maxi-mini);
            }
        }

        return ans;
    }
};