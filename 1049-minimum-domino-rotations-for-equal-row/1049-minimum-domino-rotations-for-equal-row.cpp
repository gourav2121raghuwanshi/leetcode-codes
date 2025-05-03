class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> mp;
        int n = tops.size();
        for (int i = 0; i < n; ++i) {
            // if (mp[tops[i]] == mp[bottoms[i]]) {
                ++mp[tops[i]];
                ++mp[bottoms[i]];
            // }
        }
        int maxi = -1;
        int mfreq = 0;
        for (auto& i : mp) {
            if (i.second > mfreq) {
                mfreq = i.second;
                maxi = i.first;
            }
        }
        if (maxi == -1)
            return maxi;
        int c=0;
        int cc=0;
        for (int i = 0; i < n; i++) {
            if (tops[i] != maxi && bottoms[i] != maxi)
                return -1;
            if(tops[i]==maxi)++c;
             if(bottoms[i]==maxi)++cc;
        }

        return min(n - c,n-cc);
    }
};