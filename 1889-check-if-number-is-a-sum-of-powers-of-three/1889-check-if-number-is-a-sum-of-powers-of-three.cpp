// class Solution {
// public:
//     bool checkPowersOfThree(int n) {
//         vector<int> arr = {1,     3,      9,      27,      81,
//                            243,   729,    2187,   6561,    19683,
//                            59049, 177147, 531441, 1594323, 4782969};
//         int j=arr.size()-1;
//         while(n>0){
//             while(n>0 && j>=0 && arr[j]<=n){
//                 n-=arr[j];
//             }
//             if(j>=0 && n<arr[j]){
//                 --j;
//              }
//              if(j<0) break;
//         }
//         return n==0;
//     }
// };
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> arr = {1,     3,      9,      27,      81,
                           243,   729,    2187,   6561,    19683,
                           59049, 177147, 531441, 1594323, 4782969};
        int j = arr.size() - 1;

        while (n > 0 && j >= 0) {
            if (arr[j] <= n) {
                n -= arr[j];  // Subtract the largest possible power of 3
            }
            j--;  // Move to the next smaller power of 3
        }
        return n == 0;
    }
};
