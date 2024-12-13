class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int,int>>st;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            st.insert({nums[i],i});
        }
        unordered_map<int,bool>mark;
        while(!st.empty()){
            auto front=*st.begin();
            st.erase(st.begin());
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