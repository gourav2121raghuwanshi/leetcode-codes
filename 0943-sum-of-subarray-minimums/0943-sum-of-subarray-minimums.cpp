class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod=1e9+7;
        int n=arr.size();
        vector<int>prevSmall(n,-1);
        vector<int>nextSmall(n,n);
        stack<int>st;
        for(int i=0;i<n;++i){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) prevSmall[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(!st.empty()) nextSmall[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            ans = (ans*1LL+ ((nextSmall[i]-i)*1LL*(i-prevSmall[i]))*1LL*arr[i])%mod;
        }
        return ans;
    }
};