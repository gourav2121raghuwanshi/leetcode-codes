class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int reach=nums[0];
        int jump=1;
        int j=0;
        while(reach<n-1){
            int curr=reach;
            for(;j<=min(reach,n-1);++j){
                curr=max(curr,nums[j]+j);
            }
            if(curr==reach) return -1;
            reach=curr;
            ++jump;
        }
        return jump;
    }
};