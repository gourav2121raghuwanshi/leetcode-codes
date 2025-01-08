class Solution {
public:
    bool hasMatch(string s, string p) {
        string a, b;
        bool f = true;
        for (auto& i : p) {
            if (i == '*') {
                f = false;
            } else if (f)
                a.push_back(i);
            else
                b.push_back(i);
        }
        auto idx = s.find(a);
        if (!a.empty() && idx == string::npos)
            return false;

        if (!b.empty() && s.find(b, idx + a.size()) == string::npos)
            return false;

        return 1;
    }
};