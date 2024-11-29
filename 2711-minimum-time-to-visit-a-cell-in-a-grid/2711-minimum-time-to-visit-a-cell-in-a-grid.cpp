class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    int getIdx(int i, int j) { return i * m + j; }

public:
    int minimumTime(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        if(n==1 && m==1) return 0;
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        vector<int> dist(n * m, INT_MAX);
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
        q.push({0, 0});
        dist[0] = 0;
        int t = 1;
        while (!q.empty()) {

            auto front = q.top();
            q.pop();
            int time = front.first;
            int index = front.second;
            int x = index / m;
            int y = index % m;
            if (x == n - 1 && y == m - 1)
                return time;
            for (auto& j : dir) {
                int dx = j.first + x;
                int dy = j.second + y;
                int idx = getIdx(dx, dy);
                if (dx >= 0 && dx < n && dy >= 0 && dy < m ) {
                    int timeWeCanGetToIt= ((grid[dx][dy]-time)&1)?0:1;
                    int nextTime=max(time+1,grid[dx][dy]+timeWeCanGetToIt);
                    if (dist[idx]>nextTime) {
                        dist[idx] = nextTime;
                        q.push({nextTime, idx});
                    }
                    
                }
            }
        }
        return -1;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();