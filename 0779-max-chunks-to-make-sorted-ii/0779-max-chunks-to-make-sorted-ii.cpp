class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();
        vector<vector<int>> maxNumInrange(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int maxi = -1e9;
            for (int j = i; j < n; ++j) {
                maxi = max(maxi, arr[j]);
                maxNumInrange[i][j] = maxi;
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i; j < n; ++j) {
        //         cout << maxNumInrange[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int i = 0;
        int ans = 0;
        while (i < n) {
            ++ans;
            int maxi = arr[i];
            int idx = i;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] < maxi) {
                    idx = j;
                }
                maxi = max(maxi, maxNumInrange[i][idx]);
            }
            i = idx + 1;
        }
        return ans;
    }
};