long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2)
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
        unordered_map<int, int> score;
        vector<pair<int, int>> v;
        // Correct computation of prime score (count of distinct prime factors)
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if (score.count(val)) {
                v.push_back({score[val], i});
                continue;
            }
            int temp = val;
            int cnt = 0;
            for (int j = 2; j * j <= temp; ++j) {
                if (temp % j == 0) {
                    cnt++;
                    while (temp % j == 0) {
                        temp /= j;
                    }
                }
            }
            if (temp > 1)
                cnt++;
            score[val] = cnt;
            v.push_back({cnt, i});
        }

        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; ++i) {
            while (st.top() != -1 && v[st.top()].first < v[i].first)
                st.pop();
            left[i] = st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        st.push(-1);

        for (int i = n - 1; i >= 0; --i) {
            while (st.top() != -1 && v[st.top()].first <= v[i].first)
                st.pop();
            right[i] = st.top();
            if (right[i] == -1)
                right[i] = n;
            st.push(i);
        }
        vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();++i){
            ans.push_back({nums[i],i});
        }
         sort(ans.rbegin(), ans.rend());
        // vector<pair<int, pair<int, int>>> ans;
        // for/ (int i = 0; i < n; ++i) {
            // int range = (i - left[i]) * (right[i] - i);
        //     // ans.push_back({v[i].first, {v[i].second, range}});
        //     ans.push_back({nums[i],range});
        // }
        sort(ans.rbegin(), ans.rend());
        int res = 1;
        for (auto& i : ans) {
            
            int idx=i.second;
            int val = i.first;
            long long range = (idx - left[idx]) *1LL* (right[idx] - idx);
            long long use = min(k*1LL, range);
            res = (res * modPow(val, use, (int)1e9 + 7)) % ((int)1e9 + 7);
            k -= use;
            if (k == 0)
                break;
        }
        return res;
    }
};