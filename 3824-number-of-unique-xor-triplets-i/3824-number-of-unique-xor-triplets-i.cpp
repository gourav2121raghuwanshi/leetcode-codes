class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int ans=0;
        int j=0;
        int n=nums.size();
        if(n<=2) return n;
        int maxi=*max_element(nums.begin(),nums.end());
        while(ans<maxi){
            ans=pow(2,j++);
        }
        if((n&(n-1))==0) ans+=n;
        return ans;

    }
};