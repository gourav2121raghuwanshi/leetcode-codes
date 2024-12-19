class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto& i : tasks) {
            ++freq[i - 'A'];
        }
        priority_queue<pair<int, char>>      pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] != 0) {
                pq.push({freq[i], i + 'A'});
            }
        }
        int ans = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ++ans;
            top.first--;
            vector<pair<int, char>> v;
            int k = n;
            if(pq.empty() && top.first>0){
                ans+=k;
                if(top.first)pq.push(top);
                continue;
            }else if(pq.empty() && top.first==0) break;
            while (k-- ) {
                ++ans;
                if (!pq.empty()) {
                    auto t = pq.top();
                    pq.pop();
                    t.first--;
                    if (t.first)
                        v.push_back(t);
                }
                if(pq.empty() && top.first==0) break;
            }
            if(top.first)pq.push(top);
            for (auto& i : v)
                pq.push(i);
        }
        return ans;
    }
};