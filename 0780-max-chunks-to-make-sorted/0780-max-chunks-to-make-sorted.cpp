class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // appraoch1      // logic :if at index i :
        //  prefMax(Not Include i) < SuffMin(include i) [strictly less because all unique elements]
        //   (then chunk++ at index i)

        // approach2 : make array b=arr
        //  sort array b
        //  now take two prefix sums one for arr and one for b
        //  if at any index two sums becomes same (can make chunk at that index)

        int n = arr.size();
        int ans = 0;
        vector<int> prefMax = arr;
        vector<int> suffMin = arr;
        for (int i = 1; i < n; ++i) {
            prefMax[i] = max(prefMax[i], prefMax[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(suffMin[i], suffMin[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            int prevMax = (i > 0) ? prefMax[i - 1] : -1;
            int nextMin = suffMin[i];
            if (prevMax < nextMin)
                ++ans;
        }
        return ans;
    }
};