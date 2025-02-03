class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1;
        int c=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1]){
                ++c;
            }else{
                inc=max(inc,c);
                 c=1;
                 }
        }
        inc=max(inc,c);

        int dec=1;
         c=1;
        for(int i=nums.size()-2;i>=0;--i){
            if(nums[i]>nums[i+1]){
                ++c;
            }else{
                 dec=max(dec,c);
                 c=1;
                 }
        }
        dec=max(dec,c);
        return max(inc,dec);
    }
};