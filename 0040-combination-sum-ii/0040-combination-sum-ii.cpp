class Solution {
    vector<vector<int>> ans;
    void solve(int i, vector<int>& candidates, int t, vector<int> v) {
        if (t == 0) {
            ans.push_back(v);
        }
        if (i >= candidates.size()) {
            return;
        }
        for (int j = i; j < candidates.size(); ++j) {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] <= t) {
                v.push_back(candidates[j]);
                solve(j + 1, candidates, t - candidates[j], v);
                v.pop_back();
            } else
                break;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, {});
        return ans;
    }
};