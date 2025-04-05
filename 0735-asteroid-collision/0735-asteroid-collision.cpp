class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        for (auto& i : asteroids) {
            if (v.empty())
                v.push_back(i);
            else if (i > 0) {
                // moving to right
                v.push_back(i);
            } else {
                bool equal = false;
                while (!v.empty() && v.back() > 0 && v.back() <= abs(i)) {
                    if (v.back() == abs(i)) {
                        equal = true;
                        v.pop_back();
                        break;
                    }
                    v.pop_back();
                }
                if (!v.empty() && v.back() > 0 && v.back() > abs(i))
                    continue;
                if (!equal)
                    v.push_back(i);
            }
        }
        return v;
    }
};