class Solution {
    // refer : https://www.youtube.com/watch?v=LVV5_MOzdq4
    unordered_map<int, vector<int>> adj;
    unordered_set<int> vis;

    int bfs(int node, unordered_set<int>& st) {
        queue<pair<int, int>> q; // {node, maxDist}
        int maxDist = 0;
        q.push({node, 0});
        int ans = 0;

        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            int currNode = f.first;
            int dis = f.second;
            maxDist = max(dis, maxDist);

            for (auto& j : adj[currNode]) { // Fix traversal
                if (!st.count(j)) {
                    st.insert(j);
                    ++ans;
                    q.push({j, dis + 1});
                }
            }
        }
        return maxDist;
    }

public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        for (int i = 0; i < n; ++i) {
            adj[favorite[i]].push_back(i);
        }

        int ans = 0;
        int maxCycleLen = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis.count(i)) {
                int currNode = i;
                int nodeCount = 0;
                unordered_map<int, int> nodes;

                while (!vis.count(currNode)) {
                    vis.insert(currNode);
                    nodes[currNode] = nodeCount;
                    ++nodeCount;
                    int nextNode = favorite[currNode];

                    if (vis.count(nextNode)) {
                        if (nodes.find(nextNode) != nodes.end()) {
                            int cycleLen = nodeCount - nodes[nextNode];
                            maxCycleLen = max(maxCycleLen, cycleLen);
                            
                            if (cycleLen == 2) {
                                unordered_set<int> st;
                                st.insert(currNode);
                                st.insert(nextNode);
                                ans += 2 + bfs(currNode, st) + bfs(nextNode, st);
                            }
                        }
                        break;
                    } else {
                        currNode = nextNode;
                    }
                }
            }
        }

        return max(ans, maxCycleLen);
    }
};
