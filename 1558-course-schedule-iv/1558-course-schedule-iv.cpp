class Solution {
    unordered_map<int, unordered_set<int>> adj;      // Use unordered_set for adj to prevent duplicates
    unordered_map<int, unordered_set<int>> requiress;
    
   
    
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for (auto& i : prerequisites) {
            adj[i[0]].insert(i[1]);  // Correct usage of unordered_set
        }
        
        vector<bool> vis(numCourses, false);
        

        // Fill the requiress map with prerequisites
        for (auto& i : prerequisites) {
            requiress[i[1]].insert(i[0]);
        }

   // Step 3: Propagate reachability to account for indirect prerequisites
        for (int i = 0; i < numCourses; ++i) {
            for (int j = 0; j < numCourses; ++j) {
                if (requiress[j].count(i)) {
                    requiress[j].insert(requiress[i].begin(), requiress[i].end());
                }
            }
        }

        vector<bool> ans;
        for (auto& query : queries) {
            int tocheck = query[0];
            int forr = query[1];
            if (requiress[forr].count(tocheck)) {
                ans.push_back(true);  // Using true instead of 1
            } else {
                ans.push_back(false); // Using false instead of 0
            }
        }
        return ans;
    }
};
