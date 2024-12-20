class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int>st;
        int n=as.size();
        for(int i=0;i<n;i++){

            while(as[i]<0 && !st.empty() && st.top()>0 && st.top()<abs(as[i]))
                st.pop();
            if(!st.empty() && as[i]<0 && st.top()>0 && st.top()>abs(as[i])) continue;
             if(!st.empty() && as[i]<0 && st.top()>0 && st.top()==abs(as[i])){
                st.pop();
             }else st.push(as[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};