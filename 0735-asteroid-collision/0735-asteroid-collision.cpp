class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int> ans;

        for (int i = 0; i < as.size(); ++i) {
            // Case 1: No collision, push the asteroid
            if (ans.empty() || as[i] > 0 || ans.back() < 0) {
                ans.push_back(as[i]);
            } else {
                // Case 2: Potential collision
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(as[i])) {
                    ans.pop_back(); // Remove smaller positive asteroid
                }

                // Case 3: Same size, both explode
                if (!ans.empty() && ans.back() > 0 && ans.back() == abs(as[i])) {
                    ans.pop_back();
                }
                // Case 4: Push negative asteroid if no more collision
                else if (ans.empty() || ans.back() < 0) {
                    ans.push_back(as[i]);
                }
            }
        }

        return ans;
    }
};
