class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int m = part.size();
        for (auto& i : s) {
            ans += i;
            int size = ans.size();
            // string lastPart=
            if (size >= m && ans.substr(size - m) == part) {
                int z = m;
                while (z--)
                    ans.pop_back();
            }
        }

        return ans;
    }
};