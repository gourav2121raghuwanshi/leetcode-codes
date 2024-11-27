class Solution {
    vector<vector<int>> required = {{1, 2, 3}, {4, 5, 0}};
    
    bool match(vector<vector<int>>& board) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != required[i][j])
                    return false;
            }
        }
        return true;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        if (match(board))
            return 0;
        
        int turn = 1;
        set<vector<vector<int>>> vis;
        vis.insert(board);
        
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<vector<vector<int>>> q;
        q.push(board);
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto temp = q.front();
                q.pop();
                
                int x, y;
                // Find the position of '0' in the current board state (temp)
                for (int i = 0; i < 2; ++i) {
                    bool f = false;
                    for (int j = 0; j < 3; ++j) {
                        if (temp[i][j] == 0) { // Use temp instead of board
                            x = i;
                            y = j;
                            f = true;
                            break;
                        }
                    }
                    if (f)
                        break;
                }
                
                // Try all four possible moves (up, down, left, right)
                for (auto& nxy : dir) {
                    auto front = temp; // Make a fresh copy of temp for each move
                    int nr = x + nxy.first;
                    int nc = y + nxy.second;
                    if (nr >= 0 && nc >= 0 && nr < 2 && nc < 3) {
                        // Perform the swap
                        swap(front[x][y], front[nr][nc]);
                        
                        // Check if the goal state is reached
                        if (match(front))
                            return turn;
                        
                        // If not visited, add the new state to the queue
                        if (!vis.count(front)) {
                            vis.insert(front);
                            q.push(front);
                        }
                    }
                }
            }
            ++turn;
        }
        
        return -1;
    }
};
