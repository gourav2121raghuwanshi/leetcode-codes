// class Solution {
//     int dp[501][501];
//     // int solve(int i, int j, string& a, string& b) {
//     //     if (i >= a.size() && j >= b.size())
//     //         return 0;
//     //     if (i >= a.size())
//     //         return b.size() - j;
//     //     if (j >= b.size())
//     //         return a.size() - i;

//     //     if (dp[i][j] != -1)
//     //         return dp[i][j];
//     //     if (a[i] == b[j])
//     //         return dp[i][j] = solve(i + 1, j + 1, a, b);
//     //     else {
//     //         // ins
//     //         int ins = solve(i, j + 1, a, b);
//     //         // del
//     //         int del = solve(i + 1, j, a, b);
//     //         // rep
//     //         int replace = solve(i + 1, j + 1, a, b);
//     //         return dp[i][j] = min({ins, del, replace}) + 1;
//     //     }
//     // }

// public:
//     int minDistance(string a, string b) {
//         memset(dp, 0, sizeof(dp));
//         int n = a.size();
//         int m = b.size();
//         vector<int>prev(m+1,0);
//         vector<int>curr(m+1,0);
//         // for (int i = 0; i <= n; i++) {
//         //     dp[i][m] = n - i;
//         // }
//         for (int j = 0; j <= m; ++j) {
//             prev[j] = m - j;
//         }
//         for (int i = n-1; i >= 0; --i) {
//             curr[i]=n-i;
//             for (int j = m-1; j >= 0; --j) {
//                 if (a[i] == b[j])
//                      curr[j] = prev[j+1];
//                 else {
//                     // ins
//                     int ins = curr[j+1]; 
//                     // solve(i, j + 1, a, b);
//                     // del
//                     int del =  prev[j];
//                     // solve(i + 1, j, a, b);
//                     // rep
//                     int replace =  dp[i+1][j+1]; 
//                     // solve(i + 1, j + 1, a, b);
//                      dp[i][j] = min({ins, del, replace}) + 1;
//                 }
//             }
//         }
//         return dp[0][0];
//         // return solve(0, 0, word1, word2);
//     }
// };
class Solution {
    int dp[501][501];
    // int solve(int i, int j, string& a, string& b) {
    //     if (i >= a.size() && j >= b.size())
    //         return 0;
    //     if (i >= a.size())
    //         return b.size() - j;
    //     if (j >= b.size())
    //         return a.size() - i;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (a[i] == b[j])
    //         return dp[i][j] = solve(i + 1, j + 1, a, b);
    //     else {
    //         // ins
    //         int ins = solve(i, j + 1, a, b);
    //         // del
    //         int del = solve(i + 1, j, a, b);
    //         // rep
    //         int replace = solve(i + 1, j + 1, a, b);
    //         return dp[i][j] = min({ins, del, replace}) + 1;
    //     }
    // }

public:
    int minDistance(string a, string b) {
        memset(dp, 0, sizeof(dp));
        int n = a.size();
        int m = b.size();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        // for (int i = 0; i <= n; i++) {
        //     dp[i][m] = n - i;
        // }
        for (int j = 0; j <= m; ++j) {
            prev[j] = m - j;
        }
        for (int i = n-1; i >= 0; --i) {
            curr[m]=n-i;
            for (int j = m-1; j >= 0; --j) {
                if (a[i] == b[j])
                     curr[j] = prev[j+1];
                else {
                    // ins
                    int ins = curr[j+1]; 
                    // solve(i, j + 1, a, b);
                    // del
                    int del =  prev[j];
                    // solve(i + 1, j, a, b);
                    // rep
                    int replace =  prev[j+1]; 
                    // solve(i + 1, j + 1, a, b);
                     curr[j] = min({ins, del, replace}) + 1;
                }
            }
            prev=curr;
        }
        return prev[0];
        // return solve(0, 0, word1, word2);
    }
};