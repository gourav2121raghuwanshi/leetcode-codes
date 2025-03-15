class Solution {
    int longestPath;
    int minNodes;
    vector<vector<pair<int, int>>> adj;

    void solve(int node, int par, int s, int e, int pathLengthSum,
               vector<int>& pathLen, unordered_map<int, int> &lastIdx,
               vector<int>& nums) {
         int lastidx=lastIdx.count(nums[node])?lastIdx[nums[node]]:-1;
       
     
            while (s <= lastidx) {
                pathLengthSum -= pathLen[s];
                ++s;
            }

        if (pathLengthSum > longestPath) {
            longestPath = pathLengthSum ;
            minNodes = e - s + 1;
        } else if (pathLengthSum == longestPath) {
            minNodes = min(minNodes, e - s + 1);
        }
    
        lastIdx[nums[node]] = e;

        for (auto& i : adj[node]) {
            if (i.first != par) {
                pathLen.push_back(i.second);
                solve(i.first, node, s, e + 1, pathLengthSum + i.second,
                      pathLen, lastIdx, nums);
                pathLen.pop_back();
            }
        }
        lastIdx[nums[node]]=lastidx;
    }

public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges,
                                   vector<int>& nums) {
        int n = nums.size();
        adj.resize(n);
        for (auto& i : edges) {
            int a = i[0];
            int b = i[1];
            int w = i[2];
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        longestPath = 0;
        minNodes = 1e9;
        int s = 0; // sliding window
        int e = 0;
        int pathLengthSum = 0;
        vector<int> pathLen;
        unordered_map<int, int> lastIdx;

        solve(0, -1, s, e, pathLengthSum, pathLen, lastIdx, nums);
        return {longestPath, minNodes};
    }
};