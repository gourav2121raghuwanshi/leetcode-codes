class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (auto& i : s) {
            ++freq[i - 'a'];
        }
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i])
                pq.push({i + 'a', freq[i]});
        }
        string ans = "";
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int n = min(top.second, repeatLimit);
            for (int i = 0; i < n; ++i)
                ans.push_back(top.first);

            top.second -= n;

            if (!pq.empty() && top.second > 0) {
                auto stop = pq.top();
                pq.pop();
                ans.push_back(stop.first);
                stop.second -= 1;
                if (stop.second > 0) {
                    pq.push({stop.first, stop.second});
                }
                if (top.second > 0) {
                    pq.push({top.first, top.second});
                }
            }
        }
        return ans;
    }
};