class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       vector<vector<int>>v;
       for(auto&i:nums) {
        v.push_back({i-k,i+k});
       }
       sort(v.begin(),v.end());
       int ans=1;
       deque<vector<int>>q;
       q.push_back(v[0]);    
       for(int i=1;i<v.size();++i){
        while(!q.empty() && q.front()[1]<v[i][0])q.pop_front();
        q.push_back(v[i]);
        ans=max(ans,(int)q.size());
       }
       return ans;
    }
};