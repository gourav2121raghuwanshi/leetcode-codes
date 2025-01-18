class Solution {
    using p = pair<int, pair<int, int>>;

public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    vector<vector<int>>price(n,vector<int>(m,1e9));
    price[0][0]=0;
    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int x = front.second.first;
        int y = front.second.second;
        int cost = front.first;
        if (x == n - 1 && y == m - 1)
            return cost;
        for (int i = 0; i <= 3; i++) {
            if (grid[x][y] == i + 1) {

                if (dir[i].first + x >= 0 && dir[i].second + y >= 0 &&
                    dir[i].first + x < n && dir[i].second + y < m && price[dir[i].first + x ][ dir[i].second + y]>cost) {
                    pq.push({cost, {dir[i].first + x, dir[i].second + y}});
                    price[dir[i].first + x ][ dir[i].second + y]=cost;
                }
            }else{
                  if (dir[i].first + x >= 0 && dir[i].second + y >= 0 &&
                    dir[i].first + x < n && dir[i].second + y < m &&  price[dir[i].first + x ][ dir[i].second + y]>cost+1) {
                    pq.push({cost+1, {dir[i].first + x, dir[i].second + y}});
                    price[dir[i].first + x ][ dir[i].second + y]=cost+1;
                }
            }
        }
    }
    return -1;
}
}
;