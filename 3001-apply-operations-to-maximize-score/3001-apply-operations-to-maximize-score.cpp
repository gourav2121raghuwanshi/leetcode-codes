long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2==1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> NumIdx; // nums with idx
        
        unordered_map<int, int> score;           // Cache for prime scores
        vector<int> v;                // Pair: {prime score, index}

        // Compute prime score (count of distinct prime factors) for each number.
        for (int i = 0; i < n; ++i) {
            NumIdx.push_back({nums[i], i});
            int val = nums[i];
            if (score.count(val)) {
                v.push_back(score[val]);
                continue;
            }
            int temp = val, cnt = 0;
            for (int j = 2; j * j <= temp; ++j) {
                if (temp % j == 0) {
                    cnt++;
                    while (temp % j == 0)
                        temp /= j;
                }
            }
            if (temp > 1)
                cnt++;
            score[val] = cnt;
            v.push_back(cnt);
        }


        // Compute left and right boundaries using a monotonic stack.
        vector<int> left(n), right(n);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; ++i) {
            while (st.top() != -1 && v[st.top()] < v[i])
                st.pop();
            left[i] = st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        st.push(-1);
        for (int i = n - 1; i >= 0; --i) {
            while (st.top() != -1 && v[st.top()] <= v[i])
                st.pop();
            right[i] = (st.top() == -1 ? n : st.top());
            st.push(i);
        }

        // Sort in descending order by the number's value.
        sort(NumIdx.rbegin(), NumIdx.rend());

        int res = 1;
        const int MOD = 1000000007;
        // Use candidates in sorted order to maximize the score.
        for (auto& candidate : NumIdx) {
            int val = candidate.first;
            int idx = candidate.second;
            long long range = (idx - left[idx]) * 1LL * (right[idx] - idx);
            long long use = min((long long)k, range);
            res = (int)((res * modPow(val, use, MOD)) % MOD);
            k -= use;
            if (k == 0)
                break;
        }
        return res;
    }
};
