class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            auto [freq1, char1] = pq.top();
            pq.pop();

            if (!ans.empty() && ans.size() >= 2 &&
                ans[ans.size() - 1] == char1 && ans[ans.size() - 2] == char1) {
                if (pq.empty()) {
                    break;
                }

                auto [freq2, char2] = pq.top();
                pq.pop();

                ans.push_back(char2);
                if (--freq2 > 0) {
                    pq.push({freq2, char2});
                }

                pq.push({freq1, char1});
            } else {
                int useCount = min(2, freq1);
                ans.append(useCount, char1);
                freq1 -= useCount;
                if (freq1 > 0) {
                    pq.push({freq1, char1});
                }
            }
        }

        return ans;
    }
};
