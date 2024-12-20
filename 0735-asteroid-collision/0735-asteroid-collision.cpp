class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int> ans;
        int n = as.size();
        for (int i = 0; i < n; i++) {

            while (as[i] < 0 && !ans.empty() && ans.back() > 0 &&
                   ans.back() < abs(as[i]))
                ans.pop_back();
            if (as[i] < 0 && !ans.empty() && ans.back() > 0 &&
                ans.back() > abs(as[i]))
                continue;
            if (as[i] < 0 && !ans.empty() && ans.back() > 0 &&
                ans.back() == abs(as[i])) {
                ans.pop_back();
            } else
                ans.push_back(as[i]);
        }

        return ans;
    }
};