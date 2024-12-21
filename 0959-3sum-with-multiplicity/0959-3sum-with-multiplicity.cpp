class Solution {
    // a1a2 b1b2 c1c2 2*2*2
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,long long>mp;
        long long ans=0;
        const int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            ans= (ans+mp[target-arr[i]])%mod;
            for(int j=0;j<i;++j){
                ++mp[arr[i]+arr[j]];
            }
        }
        return ans;

    }
};