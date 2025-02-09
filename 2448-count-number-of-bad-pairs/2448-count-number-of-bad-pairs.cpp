class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // j - i != nums[j] - nums[i]
        // nums[i]-i != nums[j]-j  (required Condition)

        vector<int>temp;
        int n=nums.size();

        unordered_map<int,int>mp;
        for(int i=0;i<n;++i){
            ++mp[nums[i]-i];
            temp.push_back(nums[i]-i);
        }

        long long ans=0;
        
        for(int i=0;i<n;++i){
            int curr=temp[i];
            // now we want all those elements whose are not equal to this
            --mp[curr];
            int same=mp[curr];
            int notsame=(n-i-1)-same;
            ans+=1LL*notsame;
        }

        return ans;
    }
};