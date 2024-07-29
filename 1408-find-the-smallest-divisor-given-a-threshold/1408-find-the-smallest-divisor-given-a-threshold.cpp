class Solution {
    bool isVal(int mid,vector<int>& nums, int th){
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=ceil(nums[i]*1.0/mid);
        }
        return sum<=th;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=1e6;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isVal(mid,nums,threshold)){
                ans=mid;
                e=mid-1;
            }else s=mid+1;
        }
        return ans;
    }
};