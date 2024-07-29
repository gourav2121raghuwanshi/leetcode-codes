class Solution {
    bool isVal(long long mid, vector<int>& piles, int h) {
        long long sum = 0;
        for (int i = 0; i < piles.size(); ++i) {
            sum += ceil((piles[i]*1.0)/ mid);
            if(sum>h) return false;
        }
        return sum <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 1;
        long long e = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            if (isVal(mid, piles, h)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return ans;
    }
};