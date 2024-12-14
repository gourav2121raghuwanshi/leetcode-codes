class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=nums[0];
        int n=nums.size();
        
        for(int i=1;i<n;++i){
            if(reach<i) return false;
            reach=max(reach,nums[i]+i);
        }
        return reach>=n-1;
    }
};