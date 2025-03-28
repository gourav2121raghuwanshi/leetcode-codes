class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int count = 0;
        vector<pair<int, int>> q;
        // map<int, int> mp;
        for (int i = 0; i < queries.size(); ++i) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> vis(n, vector<int>(m, false));
        vector<int> ans(queries.size());
        vis[0][0] = true;
        for (auto& i : q) {
            int val = i.first;
            int idx=i.second;
            if (pq.empty() || pq.top()[0] >= val) {
                ans[idx]=count;
                continue;
            }
            while (!pq.empty()) {
                auto top = pq.top();
                if (top[0] >= val)
                    break;
                pq.pop();
                ++count;
                for (auto& i : dir) {
                    int dx = i.first + top[1];
                    int dy = i.second + top[2];
                    if (dx >= 0 && dx < n && dy >= 0 && dy < m &&
                        !vis[dx][dy]) {
                        vis[dx][dy] = true;
                        pq.push({grid[dx][dy], dx, dy});
                    }
                }
            }
            ans[idx] = count;
        }
       
        return ans;
    }
};