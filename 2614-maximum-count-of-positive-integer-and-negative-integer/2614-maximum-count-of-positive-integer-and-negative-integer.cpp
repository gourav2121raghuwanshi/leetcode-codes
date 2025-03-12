class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pi=0;
        int ni=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<0) ++ni;
            else if(nums[i]>0) ++pi;
        }
        return max(pi,ni);
    }
};