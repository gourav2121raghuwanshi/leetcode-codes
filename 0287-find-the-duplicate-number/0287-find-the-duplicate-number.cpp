class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n){
            int idx=nums[i]-1;
            if(nums[idx]!=nums[i]){
                swap(nums[idx],nums[i]);
            }else ++i;
        }
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1) return nums[i];
        }
        return -1;
    }
};