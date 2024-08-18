class Solution {
    void make(vector<int>& a, vector<int>& b, vector<int>& ans) {
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size()) {
            ans.push_back(a[i++]);
            ans.push_back(b[j++]);
        }
    }

public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> a, b;
        for (auto& i : nums) {
            if (i < 0)
                a.push_back(i);
            else
                b.push_back(i);
        }
        vector<int> ans;
        make(b, a, ans);
        return ans;
    }
};