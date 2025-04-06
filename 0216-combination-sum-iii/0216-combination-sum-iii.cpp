// class Solution {
//     vector<vector<int>> ans;
//     void solve(int sum,int n,int k,vector<int>&v,int mask){
//         if(sum==n){
//             if(k==v.size())
//             ans.push_back(v);
//             return;
//         }
//         if(v.size()>k || sum>n) return;

//         for(int i=1;i<=9;++i){
//             if(mask&(1<<(i-1))){
//                 // mask^=(1<<(i-1));
//                 int new_mask = mask ^ (1 << (i - 1));
//                 v.push_back(i);
//                 solve(sum+i,n,k,v,new_mask);
//                 v.pop_back();
//                 // mask^=(1<<(i-1));
//             }
//         }
//     }
// public:
//     vector<vector<int>> combinationSum3(int k, int n) {

//         vector<int>v;
//         solve(0,n,k,v,(1<<9)-1);

//         return ans;
//     }
class Solution {
    vector<vector<int>> ans;

    void solve(int sum, int num, int n, int k, vector<int>& v, int mask) {
        if (sum == n) {
            if (v.size() == k)
                ans.push_back(v);
            return;
        }
        if (v.size() > k || sum > n)
            return;

        for (int i = num; i <= 9; ++i) {
            if (mask & (1 << (i - 1))) {
                v.push_back(i);
                mask = mask ^ (1 << (i - 1));
                solve(sum + i, i + 1, n, k, v, mask);
                mask = mask ^ (1 << (i - 1));
                v.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(0, 1, n, k, v, (1 << 9) - 1);
        return ans;
    }
};

// };