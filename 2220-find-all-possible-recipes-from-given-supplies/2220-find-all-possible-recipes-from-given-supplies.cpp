
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, vector<string>> ItisRequiredInOthers;
        unordered_map<string, int> idxOfRecipe;
        unordered_set<string> recips(recipes.begin(), recipes.end());
        unordered_set<string> avaliIng(supplies.begin(), supplies.end());
        
        int n = recipes.size();
        unordered_map<string, int> in;

        // Store the index of each recipe
        for (int i = 0; i < n; ++i) {
            idxOfRecipe[recipes[i]] = i;
            in[recipes[i]] = 0; // Initialize in-degree count
        }

        // Build dependency graph
        for (int i = 0; i < n; ++i) {
            for (auto& ing : ingredients[i]) {
                if (recips.count(ing)) {
                    ItisRequiredInOthers[ing].push_back(recipes[i]);
                    in[recipes[i]]++; // Increment in-degree
                }
            }
        }

        queue<string> q;

        // Push recipes with all ingredients available in `supplies`
        for (int i = 0; i < n; ++i) {
            bool canMake = true;
            for (auto& ing : ingredients[i]) {
                if (!avaliIng.count(ing)) {
                    canMake = false;
                    break;
                }
            }
            if (canMake) {
                q.push(recipes[i]);
            }
        }

        vector<string> ans;
        while (!q.empty()) {
            string f = q.front();
            q.pop();
            ans.push_back(f);
            avaliIng.insert(f); // Now this recipe can be used in other recipes
            
            for (auto& next : ItisRequiredInOthers[f]) {
                if (--in[next] == 0) {
                    q.push(next);
                }
            }
        }
        return ans;
    }
};
