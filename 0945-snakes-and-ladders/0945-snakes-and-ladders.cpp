class Solution {
    // Function to convert 1D value into 2D coordinates (zigzag pattern)
    pair<int, int> coordinates(int value, int n) {
        int row = (value - 1) / n;      // Convert to 0-based row
        int col = (value - 1) % n;      // Convert to 0-based column
        if (row % 2 == 1)               // Reverse column for odd rows
            col = n - 1 - col;
        return {n - 1 - row, col};      // Flip rows to start from bottom
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        // BFS initialization
        queue<pair<int, int>> q;
        q.push({1, 0});                 // Start from square 1 with 0 steps
        vector<vector<bool>> vis(n, vector<bool>(n, false)); // Visited cells

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int value = front.first;    // Current cell number
            int steps = front.second;   // Steps taken to reach here

            // Convert 1D value to 2D coordinates
            pair<int, int> rc = coordinates(value, n);
            int r = rc.first;
            int c = rc.second;

            // If we reach the last square, return the steps
            if (value == n * n) {
                return steps;
            }

            // Process the next 6 possible moves
            for (int nextVal = value + 1; nextVal <= min(value + 6, n * n); nextVal++) {
                pair<int, int> nextRC = coordinates(nextVal, n);
                int nr = nextRC.first;
                int nc = nextRC.second;

                if (!vis[nr][nc]) {
                    vis[nr][nc] = true; // Mark as visited

                    // Check if the square has a snake/ladder
                    int target = (board[nr][nc] == -1) ? nextVal : board[nr][nc];
                    q.push({target, steps + 1});
                }
            }
        }

        return -1; // If no solution, return -1
    }
};
