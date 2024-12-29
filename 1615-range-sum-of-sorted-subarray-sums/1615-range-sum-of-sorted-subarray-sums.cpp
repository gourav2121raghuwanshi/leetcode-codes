class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;++i) pq.push({nums[i],i});

        int ans=0;
        const int mod=1e9+7;
        int idx=0;
        while(!pq.empty()){
            auto front=pq.top(); pq.pop();
            int ele=front.first;
            int i=front.second;
            ++idx;
            if(idx>right) break;

            if(idx>=left && idx<=right) ans= (ans+ele)%mod;

            if(i+1<n) pq.push({ele+nums[i+1],i+1});
        }

        return ans;
    }
};