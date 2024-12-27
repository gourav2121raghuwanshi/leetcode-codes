class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int ans = 0;
        int cnt = 0;
        int c = 0;
        int r = 0;
        int o = 0;
        int a = 0;
        int k = 0;
        for (auto& i : croakOfFrogs) {
            switch (i) {
            case 'c':
                ++c;
                ++cnt;
                break;

            case 'r':
                ++r;
                break;

            case 'o':
                ++o;
                break;

            case 'a':
                ++a;
                break;

            case 'k':
                ++k;
                --cnt;
                break;
            }
            if (c < r || r < o || o < a || a < k)
                return -1;
            ans = max(ans, cnt);
        }
        if (c == r && r == o && o == a && a == k)
            return ans;
        return -1;
    }
};