class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>>adj;
        for(auto&i:tickets){
            string  a=i[0];
            string b=i[1];
            adj[a].push(b);
        }
        stack<string>st;
        st.push("JFK");
        vector<string>ans;
        while(!st.empty()){
            auto front=st.top();
            
            if(adj[front].empty()){
                ans.push_back(front);
                st.pop();
            }else{
                auto tp=adj[front].top();
                adj[front].pop();
                st.push(tp);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};