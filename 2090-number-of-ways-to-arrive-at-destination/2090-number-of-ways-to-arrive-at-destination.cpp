class Solution {
    const int mod = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);
        for (auto& i : roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<long long> dist(n, 1e11);
        vector<long long> ways(n, 1);
        ways[0] = 1;
        dist[0] = 0;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            vector<long long> f = pq.top();
            pq.pop();
            long long dis = f[0];
            int node = f[1];
            for (auto& k : adj[node]) {
                int nbr = k.first;
                long long wt = k.second;
                if (dist[nbr] > dis + wt) {
                    dist[nbr] = dis + wt;
                    ways[nbr] = ways[node];
                    pq.push({dist[nbr], nbr});
                } else if (dist[nbr] == dis + wt) {
                    ways[nbr] =( ways[nbr]+ ways[node])%mod;
                }
            }
        }
        // cout << dist[n - 1];
        return ways[n - 1];
    }
};