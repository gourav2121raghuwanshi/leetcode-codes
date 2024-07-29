class Solution {
    void solve(int i, vector<int>& v, vector<int>& candidates,
               vector<vector<int>>& ans, int t) {
        if (t == 0) {
            ans.push_back(v);
            return;
        }
        if (i >= candidates.size())
            return;

        if (candidates[i] <= t) {
            v.push_back(candidates[i]);
            solve(i, v, candidates, ans, t - candidates[i]);
            v.pop_back();
        }
        solve(i + 1, v, candidates, ans, t);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, v, candidates, ans, target);
        return ans;
    }
};