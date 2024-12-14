class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1) return ;
        int s=0;
        int m=0;
        int e=nums.size()-1;
        while(m<=e){
            if(nums[m]==0){
                swap(nums[s],nums[m]);
                ++s;
                ++m;
            }else if(nums[m]==2){
                swap(nums[m],nums[e]);
                --e;
            }else ++m;
        }
    }
};