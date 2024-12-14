class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int ans=1;
        int reach=nums[0];
        int i=0;
        while(reach<n-1){
            int curr=0;
            for(;i<=reach;++i){
                curr=max(curr,i+nums[i]);
            }
            reach=curr;
            ++ans;
        }
        return ans;
    }
};