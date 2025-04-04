class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=nums[0];
        int n=nums.size();
        for(int i=1;i<n;++i){
            if(jump<i) return false;
            jump=max(jump,nums[i]+i);
        }
        return jump>=n-1;
    }
};