class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0;
        unordered_set<int>st(banned.begin(),banned.end());
        int c=1;
        int sm=0;
        for(int i=1;i<=n;i++){
            if(sm+i>maxSum) break;
            if(!st.count(i) && sm+i<=maxSum){
                sm+=i;
                ++ans;
            }
        }
        return ans;
    }
};