class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_map<int,unordered_set<int>>factors;
        for(int i=1;i<=maxi;++i){
            int curr=i;
            for(int j=2;j<=i;++j){
                while(curr%j==0){
                    curr/=j;
                    factors[i].insert(j);
                }
            }
        }
        unordered_set<int>st;
        for(auto&j:nums){
            for(auto&i:factors[j]) st.insert(i);
        }
        return st.size();
    }
};