class Solution {
    // logic : store same char nodes in map<int,vector>, then use dfs to update parent
    // use second dfs to find subtree size for each node
    unordered_map<char, vector<int>> sameCharNodes;
    unordered_map<int, vector<int>> adj;

    unordered_map<int,vector<int>>newAdj;
    void dfs(int node, string& s, vector<int>& parent) {

        char ch = s[node];
        if (!sameCharNodes[ch].empty()) {
            parent[node] = sameCharNodes[ch].back();
        }
        sameCharNodes[ch].push_back(node);
        for(auto&j:adj[node]){
            dfs(j,s,parent);
        }
        sameCharNodes[ch].pop_back();
    }

    int dfs_find_subtree_size(int node,vector<int>&ans){
        int c=1;

        for(auto&j:newAdj[node]){
            c+=dfs_find_subtree_size(j,ans);
        }
        ans[node]=c;
        return c;
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        

        int n = parent.size();
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                adj[parent[i]].push_back(i);
            }
        }

        dfs(0, s, parent);



        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                newAdj[parent[i]].push_back(i);
            }
        }
        vector<int> ans(n);
        dfs_find_subtree_size(0,ans);
        for(auto&i:parent) cout<<i<<" ,";
        return ans;
    }
};