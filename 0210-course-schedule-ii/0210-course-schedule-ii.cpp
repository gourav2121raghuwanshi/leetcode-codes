class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<int> ans;
        unordered_map<int, vector<int>> adj;
        for (auto& i : prerequisites) {
            int a = i[0];
            int b = i[1];
            adj[b].push_back(a);
            in[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0)
                q.push(i);
        }
        int c = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            ans.push_back(front);
            ++c;
            for (auto& i : adj[front]) {
                --in[i];
                if (in[i] == 0)
                    q.push(i);
            }
        }

        if (c == numCourses)
            return ans;
        return {};
    }
};