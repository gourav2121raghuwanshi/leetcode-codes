class Solution {
    // Approach 2
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {

        int maxEle = *max_element(groups.begin(), groups.end()) + 1;
        unordered_map<int, int> factors;
        for (int i = 1; i <= (int)maxEle; ++i) {
            factors[i] = 1e9;
        }
        unordered_set<int> availableFactors;
        unordered_map<int, int> minIndexofELement;
        for (int i = 0; i < elements.size(); ++i) {
            minIndexofELement[elements[i]] = 1e9;
        }
        for (int i = 0; i < elements.size(); ++i) {
            availableFactors.insert(elements[i]);
            minIndexofELement[elements[i]] =
                min(i, minIndexofELement[elements[i]]);
        }

        for (auto& i : availableFactors) {
            for (int j = i; j <= maxEle; j += i) {
                factors[j] = min(factors[j], minIndexofELement[i]);
            }
        }

        vector<int> ans;
        for (auto& j : groups) {
            if (factors[j] != 1e9)
                ans.push_back(factors[j]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};