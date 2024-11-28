class Solution {
public:
    int takeCharacters(string s, int k) {
        int ac = 0;
        int bc = 0;
        int cc = 0;
        for (auto& i : s) {
            if (i == 'a')
                ++ac;
            else if (i == 'b')
                ++bc;
            else
                ++cc;
        }
        if (ac < k || bc < k || cc < k)
            return -1;

int n=s.size();
        int l = 0;
        int ans =n;
        for (int r = 0; r < s.size(); ++r) {
            if (s[r] == 'a')
                --ac;
            else if (s[r] == 'b')
                --bc;
            else
                --cc;

            while (ac < k || bc < k || cc < k) {
                if (s[l] == 'a')
                    ++ac;
                else if (s[l] == 'b')
                    ++bc;
                else
                    ++cc;
                ++l;
            }
            ans=min(ans,n-(r-l+1));
        }
        return ans;
    }
};