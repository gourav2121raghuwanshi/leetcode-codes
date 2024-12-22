class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1e9;
        vector<int>large(n);
        for(int i=n-1;i>=0;--i){
            maxi=max(maxi,nums[i]);
            large[i]=maxi;
        }
        int ans=0;
        int i=0;
        int j=0;
        while(j<nums.size()){
            while(i<j && nums[i]>large[j]) ++i;
            ans=max(ans,j-i);
            ++j;
        }
        return ans;
    }
};