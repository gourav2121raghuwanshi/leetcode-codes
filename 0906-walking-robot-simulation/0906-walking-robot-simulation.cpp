#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    int dist(int a, int b) { return a * a + b * b; }
    int ans = 0;
    
    // Adjust direction modulo for negative values
    int mod(int a, int b) {
        return (a % b + b) % b;
    }

public:
    set<pair<int, int>> mp;
    
    void solve(int i, int x, int y, int dir, vector<int>& commands) {
        ans = max(ans, dist(x, y));
        if (i >= commands.size())
            return;

        if (commands[i] == -2) {
            solve(i + 1, x, y, mod(dir - 1, 4), commands); // Turn left
            return;
        } else if (commands[i] == -1) {
            solve(i + 1, x, y, mod(dir + 1, 4), commands); // Turn right
            return;
        }

        for (int k = 0; k < commands[i]; ++k) {
            if (dir == 0 && !mp.count({x, y + 1})) {
                ++y;
            } else if (dir == 1 && !mp.count({x + 1, y})) {
                ++x;
            } else if (dir == 2 && !mp.count({x, y - 1})) {
                --y;
            } else if (dir == 3 && !mp.count({x - 1, y})) {
                --x;
            } else {
                break; 
            }
        }
        solve(i + 1, x, y, dir, commands);
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for (auto& obs : obstacles) {
            mp.insert({obs[0], obs[1]});
        }

        solve(0, 0, 0, 0, commands); 
        return ans;
    }
};
