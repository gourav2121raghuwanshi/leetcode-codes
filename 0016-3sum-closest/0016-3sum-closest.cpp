class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        int ans=1e9;
        int n=nums.size();
        for(int i=0;i<n-2;++i){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if (abs(sum - t) < abs( ans - t)) {
                    ans = sum;
                }
                if(sum>t) --k;
                else ++j;
            }
        }
        return ans;
    }
};