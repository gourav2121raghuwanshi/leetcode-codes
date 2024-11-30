class Solution {
    vector<int> temp;
    unordered_map<int, vector<int>> adj;

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> in;
        unordered_map<int, int> out;

        // Build the adjacency list and calculate in-degree and out-degree for each node
        for (auto& pair : pairs) {
            ++in[pair[1]];
            ++out[pair[0]];
            adj[pair[0]].push_back(pair[1]);
        }

        int start = pairs[0][0];

      for(auto&i:adj){
        if(out[i.first]-in[i.first]==1){
            start=i.first;
            break;
        }
      }

       

        vector<vector<int>> ans;
        stack<int> st;
        st.push(start);

        // Perform DFS using the stack
        while (!st.empty()) {
            int node = st.top();
            
            // If there are neighbors to visit, continue DFS
            if (!adj[node].empty()) {
                st.push(adj[node].back());
                adj[node].pop_back();
            } else {
                // If no more neighbors, add to the result
                temp.push_back(node);
                st.pop();
            }
        }

        // Reversing temp to get the correct order of the path
        reverse(temp.begin(), temp.end());

        // Build the result as a list of pairs
        for (int i = 0; i < temp.size() - 1; ++i) {
            ans.push_back({temp[i], temp[i + 1]});
        }

        return ans;
    }
};
