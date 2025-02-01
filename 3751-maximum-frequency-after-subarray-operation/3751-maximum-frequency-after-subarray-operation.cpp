class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans=0;
        int kcount=0;
        for(auto&i:nums){
            if(i==k) ++kcount;
        }

        for(int i=1;i<=50;i++){
             int curr=0;
             int maxi=0;
            for(auto&j:nums){
                if(j==i || j==k){
                    if(j==k)--curr;
                    else if(j==i) ++curr;
                    if(curr<0) curr=0;
                    maxi=max(maxi,curr);
                }
            }
            ans=max(ans,maxi);
        }
        return ans+kcount;
    }
};