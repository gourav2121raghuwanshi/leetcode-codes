class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& i : flights) {
            adj[i[0]].push_back({i[1], i[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // dist, src, cost
        int ans = 1e9;
        bool f = false;
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int dist = front.first;
            int s = front.second.first;
            int c = front.second.second;
            if (dist > k)
                continue;
            for (auto& i : adj[s]) {
                int node = i.first;
                int wt = i.second;
                if (dis[node] > c + wt) {
                    if (node == dst) {
                        f = true;
                        ans = min(ans, wt + c);
                    } else {
                        q.push({dist + 1, {node, wt + c}});
                    }
                    dis[node] = c + wt;
                }
            }
        }
        // cout<<ans;

        if (!f)
            return -1;
        else
            return ans;
    }
};