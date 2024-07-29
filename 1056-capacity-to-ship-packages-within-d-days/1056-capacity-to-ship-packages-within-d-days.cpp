class Solution {
    bool isVal(int mid, vector<int>& weights, int days) {
        int c = 1;
        int s = 0;
        for (int i = 0; i < weights.size(); ++i) {
            if (weights[i] > mid)
                return false;
            if (s + weights[i] <= mid) {
                s += weights[i];
            } else {
                ++c;
                s = weights[i];
            }
        }
        return c <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(), weights.end());
        int s = 0;
        int e = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (isVal(mid, weights, days)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return ans;
    }
};