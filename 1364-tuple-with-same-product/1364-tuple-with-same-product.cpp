class Solution {

public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long,int>prod;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                ++prod[nums[i]*1LL*nums[j]];
            }
        }
        long long ans=0;
        for(auto&i:prod){
            int cnt=i.second;
            if(cnt>1){
                ans+=cnt*(cnt-1)/2;
            }
        }
        return ans*8;
    }
};