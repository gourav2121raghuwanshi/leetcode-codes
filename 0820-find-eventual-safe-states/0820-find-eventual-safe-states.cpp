class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> out(n, 0);
        unordered_map<int, vector<int>> revadj;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            for (auto& j : graph[i]) {
                revadj[j].push_back(i);
                ++out[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (out[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto& j : revadj[front]) {
                --out[j];
                if (out[j] == 0)
                    q.push(j);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};