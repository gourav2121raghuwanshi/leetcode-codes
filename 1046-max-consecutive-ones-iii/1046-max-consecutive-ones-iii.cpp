class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int sum=0;
        int l=0;
        for(int i=0;i<nums.size();++i){
            sum+=(nums[i]==0?1:0);
            while(sum>k){
                sum+=(nums[l]==0?-1:0);
                ++l;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};