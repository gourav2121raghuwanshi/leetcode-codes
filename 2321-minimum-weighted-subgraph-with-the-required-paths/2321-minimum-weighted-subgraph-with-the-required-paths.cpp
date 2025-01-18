class Solution {
    unordered_map<int, vector<pair<int, int>>> adj;
    unordered_map<int, vector<pair<int, int>>> radj;
    
    vector<long long> dijk(int n, int start) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        pq.push({0, start});
        vector<long long> dist3(n, LLONG_MAX);
        dist3[start] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist3[u])
                continue;
            for (auto& v : adj[u]) {
                if (dist3[u] + v.second < dist3[v.first]) {
                    dist3[v.first] = dist3[u] + v.second;
                    pq.push({dist3[v.first], v.first});
                }
            }
        }
        return dist3;
    }
    vector<long long> dijk2(int n, int start) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        pq.push({0, start});
        vector<long long> dist3(n + 1, LLONG_MAX);
        dist3[start] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist3[u])
                continue;
            for (auto& v : radj[u]) {
                if (dist3[u] + v.second < dist3[v.first]) {
                    dist3[v.first] = dist3[u] + v.second;
                    pq.push({dist3[v.first], v.first});
                }
            }
        }
        return dist3;
    }

public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        for (auto& i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
            radj[i[1]].push_back({i[0], i[2]});
        }
        vector<long long> dist1 = dijk(n, src1);
        vector<long long> dist2 = dijk(n, src2);

        vector<long long> dist3 = dijk2(n, dest);

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != LLONG_MAX && dist2[i] != LLONG_MAX &&
                dist3[i] != LLONG_MAX) {
                ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};