class Solution {
    unordered_map<int, vector<int>> adj1;

    unordered_map<int, vector<int>> adj2;

    int findEnd(int node,
                unordered_map<int, vector<int>>&
                    adj) { // end means we will give farthest node from current
        queue<int> q;
        q.push(node);
        unordered_set<int> st;
        st.insert(node);
        int last = -1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int front = q.front();
                q.pop();
                last = front;
                for (auto& i : adj[front]) {
                    if (!st.count(i)) {
                        st.insert(i);
                        q.push(i);
                    }
                }
            }
        }
        return last;
    }

    vector<int> findEndToEnd(int node, unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        unordered_map<int, int> parent; // Map to store parent of each node
        unordered_set<int> visited;
        q.push(node);
        visited.insert(node);
        parent[node] = -1;

        int farthestNode = node;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            farthestNode = front; // Update the farthest node
            for (auto& neighbor : adj[front]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    parent[neighbor] = front;
                    q.push(neighbor);
                }
            }
        }

        
        vector<int> path;
        while (farthestNode != -1) {
            path.push_back(farthestNode);
            farthestNode = parent[farthestNode];
        }
        // reverse(path.begin(), path.end());
        return path;
    }

    int diameter(int node, unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        q.push(node);
        unordered_set<int> st;
        st.insert(node);
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int size = q.size();
            while (size--) {
                int front = q.front();
                q.pop();
                // last = front;
                for (auto& i : adj[front]) {
                    if (!st.count(i)) {
                        st.insert(i);
                        q.push(i);
                    }
                }
            }
        }
        return ans;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        if (edges1.empty() && edges2.empty())
            return 1;
        if (edges1.empty()) {
            for (auto& i : edges2) {
                adj2[i[0]].push_back(i[1]);
                adj2[i[1]].push_back(i[0]);
            }
            int node2 = findEnd(edges2[0][0], adj2);

            vector<int> v2 = findEndToEnd(node2, adj2);
            if (v2.size() <= 2)
                return v2.size();
            return v2.size() - 1;
        }
        if (edges2.empty()) {
            for (auto& i : edges1) {
                adj1[i[0]].push_back(i[1]);
                adj1[i[1]].push_back(i[0]);
            }

            int node1 = findEnd(edges1[0][0], adj1);

            int ans = 0;
            vector<int> v1 = findEndToEnd(node1, adj1);
            if (v1.size() <= 2)
                return v1.size();
            return v1.size() - 1;
        }
        // find end 1
        // find end 2 (along with path in vector/array)
        // their mid is root
        int maxi1 = 0;
        for (auto& i : edges1) {
            maxi1 = max(maxi1, i[0]);
            maxi1 = max(maxi1, i[1]);
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }

        ++maxi1;
        for (auto& i : edges2) {
            adj2[i[0] + maxi1].push_back(i[1] + maxi1);
            adj2[i[1] + maxi1].push_back(i[0] + maxi1);
        }

        int node1 = findEnd(edges1[0][0], adj1);
        int node2 = findEnd(edges2[0][0] + maxi1, adj2);

        int ans = 0;
        vector<int> v1 = findEndToEnd(node1, adj1);
        vector<int> v2 = findEndToEnd(node2, adj2);
        ans = max({ans, (int)v1.size() - 1, (int)v2.size() - 1});
        // for(auto&i:v1) cout<<i<<","; cout<<endl;
        // for(auto&i:v2) cout<<i<<",";
        int root1;
        int root2;

        root1 = v1[v1.size() / 2];
        root2 = v2[v2.size() / 2];

        for (const auto& [key, value] : adj2) {
            if (adj1.count(key)) {
                adj1[key].insert(adj1[key].end(), value.begin(), value.end());
            } else {
                adj1[key] = value;
            }
        }
        adj1[root1].push_back(root2);
        adj1[root2].push_back(root1);

        int last3 = findEnd(edges1[0][0], adj1);

        return diameter(last3, adj1) - 1;
    }
};