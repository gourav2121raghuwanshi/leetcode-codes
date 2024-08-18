class Solution {
    bool val(int mid,vector<int>& nums, int th){
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=ceil(nums[i]*1.0/mid);
            if(sum>th) return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(val(mid,nums,threshold)){
                ans=mid;
                e=mid-1;
            }else s=mid+1;
        }
        return ans;
    }
};