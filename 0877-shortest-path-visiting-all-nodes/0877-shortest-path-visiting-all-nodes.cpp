class Solution {

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int req = (1 << n) - 1;
        // cout << req << endl;
        vector<vector<bool>> vis(n, vector<bool>(req+1, false));
        int ans = 1e9;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.push({i, (1 << (i))});
            vis[i][(1 << (i))] = true;
        }

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, cnt] = q.front();
                q.pop();
                if (cnt == req) {
                    ans = min(ans, steps);
                    break;
                }

                for (auto& i : graph[node]) {
                    if (!vis[i][(cnt | (1 << i))]) {
                        vis[i][(cnt | (1 << i))] = 1;
                        q.push({i, (cnt | (1 << i))});
                    }
                }
            }
            ++steps;
        }

        return ans;
    }
};