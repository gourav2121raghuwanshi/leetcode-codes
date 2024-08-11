class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] != -1)
                continue;
            vis[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                auto front = q.front();
                q.pop();
                for (auto& j : graph[front]) {
                    // cout<<vis[j]<<" "<<vis[front]<<endl;
                    if (vis[j] == -1) {
                        vis[j] = 1 - vis[front];
                        q.push(j);
                    } else if (vis[j] == vis[front])
                        return false;
                }
            }
        }

        return true;
    }
};