class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>>v;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        unordered_map<int,bool>mark;
        for(auto&i:v){
            auto front=i;
            int val=front.first;
            int idx=front.second;
            if(!mark[idx]){
                mark[idx]=true;
                mark[idx-1]=true;
                mark[idx+1]=true;
                ans+=val;
            }
        }
        return ans;
    }
};