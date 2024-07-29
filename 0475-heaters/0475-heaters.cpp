class Solution {
    bool isVal(int mid, vector<int>& houses, vector<int>& heaters) {
        int i = 0;
        int j = 0;
        while (i < houses.size() && j < heaters.size()) {
            if (abs(houses[i] - heaters[j]) <= mid)
                ++i;
            else
                ++j;
        }
        return i == houses.size(); // all houses got covered
    }

public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = -1;
        int s = 0;
        int e = 1e9;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (isVal(mid, houses, heaters)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return ans;
    }
};