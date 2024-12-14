class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=-1e9;
        int n=nums.size();
        for(int i=0;i<n-2;++i){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                int diff=target-sum;
                if(abs(sum-target)<abs(ans-target)) ans=sum;
                if(diff<0) --r;
                else ++l;
            }
        }

        return ans;
    }
};