class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;
        bool pos=false;
        int maxi=-1e9;
        for(auto&i:st){
            if(i>=0){
                pos=1;
                ans+=i;
            }else maxi=max(maxi,i);

        }
        if(pos) return ans;
        return maxi;
    }
};