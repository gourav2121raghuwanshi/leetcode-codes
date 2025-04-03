class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mini=LLONG_MAX;
        long long maxi=LLONG_MIN;
        long long ans=0;
        int n=nums.size();
        if(n<3) return 0;
        vector<int>leftMax(n);
        vector<int>rightMax(n);

        leftMax[0]=nums[0];
        for(int i=1;i<n;++i){
            leftMax[i]=max(nums[i],leftMax[i-1]);
        }
        rightMax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i){
            rightMax[i]=max(rightMax[i+1],nums[i]);
        }

        for(int i=1;i<n-1;i++){
        ans=max(ans,(leftMax[i-1]-nums[i])*1LL*rightMax[i+1]);
        }

        return ans;
    }
};