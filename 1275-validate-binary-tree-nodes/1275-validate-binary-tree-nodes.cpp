class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> vis(n, false);
        vector<int> in(n, 0);

       for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                ++in[leftChild[i]];
            }
            if (rightChild[i] != -1) {
                ++in[rightChild[i]];
            }
        }

        int root = -1, rootCount = 0;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                ++rootCount;
                root = i;
            }
        }

        if (root == -1 || rootCount > 1) return false;

        queue<int> q;
        q.push(root);
        vis[root] = true;

        int visitedCount = 1;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            if (leftChild[front] != -1) {
                if (vis[leftChild[front]]) return false; 
                
                q.push(leftChild[front]);
                vis[leftChild[front]] = true;
                ++visitedCount;
            }
            if (rightChild[front] != -1) {
                if (vis[rightChild[front]]) return false;
                
                q.push(rightChild[front]);
                vis[rightChild[front]] = true;
                ++visitedCount;
            }
        }

        return visitedCount == n;
    }
};
