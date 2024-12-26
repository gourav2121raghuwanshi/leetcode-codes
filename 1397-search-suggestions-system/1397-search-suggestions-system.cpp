class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int n = products.size();
        string temp = "";
        for (auto& ch : searchWord) {
            temp.push_back(ch);
            int lb = lower_bound(products.begin(), products.end(), temp) -
                     products.begin();
            vector<string> v;
            for (int idx = lb; idx < min(n, lb + 3); ++idx) {
                if (products[idx].substr(0, temp.size()) == temp)
                    v.push_back(products[idx]);
                else
                    break;
            }
            ans.push_back(v);
        }

        return ans;
    }
};