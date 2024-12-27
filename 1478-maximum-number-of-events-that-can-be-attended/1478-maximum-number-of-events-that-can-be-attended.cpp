class Solution {
    static bool comp(const vector<int>&a,const vector<int>&b){
        if(a[1]!=b[1])
        return a[1]<b[1];
        return a[0]<b[0];
    }
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end(),comp);

        set<int>st;
        for(int i=1;i<=events[n-1][1];++i){
            st.insert(i);
        }
        int ans=0;
        for(auto&i:events){
            int start=i[0];
            int end=i[1];
            auto lb=st.lower_bound(start);
            if(lb==st.end()){
                continue;
            }else if(*lb<=end){
                ++ans;
                st.erase(*lb);
            }
        }
        return ans;
    }
};