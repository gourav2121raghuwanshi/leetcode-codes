class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {    
        int maxEle=*max_element(groups.begin(),groups.end())+1;
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

        for (int i = 1; i <= maxEle; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    if (availableFactors.count(j)) {
                        factors[i] = min(factors[i], minIndexofELement[j]);
                    }
                }
                int secEle = i / j;
                if (i % secEle == 0) {
                    if (availableFactors.count(secEle)) {
                        factors[i] = min(factors[i], minIndexofELement[secEle]);
                    }
                }
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