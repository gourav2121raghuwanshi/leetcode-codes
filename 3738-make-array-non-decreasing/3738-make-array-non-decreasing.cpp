class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans=0;
        int prev=-1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>=prev){
                ++ans;
                prev=nums[i];
            }
        }
        return ans;
    }
};