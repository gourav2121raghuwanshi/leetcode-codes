class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp1(n, 1);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] > arr[prev] && dp1[i] < dp1[prev] + 1) {
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }

        vector<int> dp2(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = n - 1; prev > i; prev--) {
                if (arr[i] > arr[prev] && dp2[i] < dp2[prev] + 1) {
                    dp2[i] = 1 + dp2[prev];
                }
            }
        }

        int maxi = -1;
        // for (int i = 0; i < n; ++i)
        // cout<<dp1[i]<<" ";
        // cout<<endl;
        // for (int i = 0; i < n; ++i)
        // cout<<dp2[i]<<" ";
        // cout<<endl;
        for (int i = 0; i < n; ++i) {
            if(dp1[i]>1 && dp2[i]>1)
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        // for (int i = 0; i < n; ++i) {
        //     maxi = max(maxi, dp1[i]);
        //     maxi = max(maxi, dp2[i]);
        // }
        return n - maxi;
    }
};