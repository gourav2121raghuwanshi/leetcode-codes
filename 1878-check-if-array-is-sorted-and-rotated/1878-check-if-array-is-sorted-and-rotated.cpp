class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) ++c;
        } 
        if(nums[0]<nums.back()) ++c;
        return c<=1;
    }

};