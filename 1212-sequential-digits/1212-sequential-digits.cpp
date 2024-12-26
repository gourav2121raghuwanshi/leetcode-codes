class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        for (int len = 1; len <= s.size(); ++len) {
            for (int start = 0; start + len <= s.size(); ++start) {
                int val = stoi(s.substr(start, len));
                if (val >= low && val <= high)
                    ans.push_back(val);
            }
        }
        return ans;
    }
};