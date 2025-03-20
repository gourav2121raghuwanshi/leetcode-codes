class Solution {

    // unordered_map<string, int> dp;

public:
    int minStickers(vector<string>& stickers, string target) {
        vector<int> freq(26, 0);
        for (auto& i : target) {
            ++freq[i - 'a'];
        }
        map<vector<int>, bool> dp;
        queue<pair<vector<int>, int>> q;
        q.push({freq, 0});
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            vector<int> f = tp.first;
            int count = tp.second;
            for (auto& s : stickers) {
                vector<int> temp = f;
                bool taken = false;
                for (int j = 0; j < s.size(); ++j) {
                    if (temp[s[j] - 'a'] > 0) {
                        --temp[s[j] - 'a'];
                        taken = 1;
                    }
                }
                if (taken) {
                    int sum = accumulate(temp.begin(), temp.end(), 0);
                    if (sum == 0)
                        return count + 1;
                    if (!dp.count(temp)) {
                        dp[temp] = 1;
                        q.push({temp, count + 1});
                    }
                }
            }
        }

        return -1;
        // int ans= solve(stickers,freq);
        // return ans>=1e7?-1:ans;
    }
};