class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto& i : tasks) {
            ++freq[i - 'A'];
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0)
                pq.push(freq[i]);
        }

        int ans = 0;

        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 1; i <= n + 1; ++i) {
                if (!pq.empty()) {
                    int top = pq.top();
                    pq.pop();
                    --top;
                     temp.push_back(top);
                }
            }

            for (auto& j : temp) {
                if (j > 0) {
                    pq.push(j);
                }
            }
            if (pq.empty())
                ans += temp.size();
            else
                ans += n + 1;
        }
        return ans;
    }
};