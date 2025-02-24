class Solution {
    unordered_map<int, vector<int>> adj;
    vector<bool> vis, visitedBob;
    unordered_map<int, int> bobTime;
    int ans = INT_MIN;

    bool bobPath(int node, int t) {
        bobTime[node] = t;
        visitedBob[node] = true;  // Mark Bob's visited nodes

        if (node == 0) return true;  // If Bob reaches the root, it's part of the path

        for (auto& j : adj[node]) {
            if (!visitedBob[j]) {
                if (bobPath(j, t + 1)) return true;  // If `true`, it's part of Bob's path
            }
        }

        // If we backtrack without reaching `0`, remove this node from Bob's path
        bobTime.erase(node);
        return false;
    }

    void alicePath(int node, int t, int amt, vector<int>& amount) {
        vis[node] = true;

        // Alice collects amount based on Bob's timing
        if (bobTime.find(node) == bobTime.end() || t < bobTime[node]) {
            amt += amount[node];  // Alice collects full amount
        } else if (bobTime[node] == t) {
            amt += amount[node] / 2;  // Alice and Bob arrive at the same time, so Alice gets half
        }

        bool isLeaf = true;
        for (auto& j : adj[node]) {
            if (!vis[j]) {
                isLeaf = false;
                alicePath(j, t + 1, amt, amount);
            }
        }

        // If Alice is at a leaf node, update the maximum profit
        if (isLeaf) {
            ans = max(ans, amt);
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vis.resize(n, false);
        visitedBob.resize(n, false);

        // Build adjacency list
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // Compute Bob's path
        bobPath(bob, 0);

        // Reset Alice's visited array
        fill(vis.begin(), vis.end(), false);

        // Compute Alice's max profit path
        alicePath(0, 0, 0, amount);

        return ans;
    }
};
