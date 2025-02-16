class Solution {
    vector<int> ans;
    bool solve(int idx, vector<int>& df, vector<int>& temp, int n) {

        if (idx == temp.size()) {
            for (auto& i : df) {
                if (i != 0)
                    return false;
            }
            ans = max(ans, temp);
            return 1;
        }
        if (idx < temp.size() && temp[idx] != -1)
            return solve(idx + 1, df, temp, n);

        for (int i = n;i>=1;--i) {
            if (df[i]) {
                --df[i];
                temp[idx] = i;
                if (i != 1 && idx + i < temp.size() && temp[idx + i] == -1) {
                    temp[idx + i] = i;
                    --df[i];
                    bool a=solve(idx + 1, df, temp, n);
                    if(a) return a;
                    ++df[i];
                    temp[idx + i] = -1;
                } else if (i == 1) {
                    bool a=solve(idx + 1, df, temp, n);
                    if(a) return a;
                }
                temp[idx] = -1;
                ++df[i];
            }
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {

        int req = 2 * n - 1;
        vector<int> freq(n + 1);
        freq[1] = 1;
        for (int i = 2; i <= n; i++)
            freq[i] = 2;

        for (int i = n;i>=1;i--) {
            vector<int> df = freq;
            vector<int> temp(req, -1);
            --df[i];
            if (i != 1) {
                temp[i] = i;
                --df[i];
            }
            temp[0] = i;
            if(solve(1, df, temp, n)) return ans;
        }
        return ans;
    }
};