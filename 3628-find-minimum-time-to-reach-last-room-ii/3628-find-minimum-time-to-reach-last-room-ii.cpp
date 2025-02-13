class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        //         // nXm
        //         //val = (i,j) = i*m+j
        //         // row  = val/m
        //         // col  = val%m
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {1, 0}}); // {cost, {alternating_move, position}}

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            auto i = pq.top();
            pq.pop();
            int cost = i.first;
            int c = i.second.first;
            int val = i.second.second;
            int row = val / m;
            int col = val % m;
            if (row == n - 1 && col == m - 1) {
                return cost;
            }
            for (auto& j : directions) {
                int nr = row + j.first;
                int nc = col + j.second;
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int newCost = max(cost + c, moveTime[nr][nc] + c);
                    if (dist[nr][nc] > newCost) {
                        int newVal = nr * m + nc;
                        int nextC = (c == 1 ? 2 : 1);
                        pq.push({newCost, {nextC, newVal}});
                        dist[nr][nc] = newCost;
                    }
                }
            }
        }
        return -1;
    }
};
