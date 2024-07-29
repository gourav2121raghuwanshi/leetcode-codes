class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n=rating.size();
        for (int i = 0; i < n; ++i) {
            int ls = 0, rs = 0;
            int ll = 0, rl = 0;
            for (int j = 0; j < i; ++j) {
                if (rating[j] < rating[i])
                    ++ls;
                else if (rating[j] > rating[i])
                    ++ll;
            }
            for (int j = i + 1; j < n; ++j) {
                if (rating[j] < rating[i])
                    ++rs;
                else if (rating[j] > rating[i])
                    ++rl;
            }
            ans += ls * rl + ll * rs;
        }
        return ans;
    }
};