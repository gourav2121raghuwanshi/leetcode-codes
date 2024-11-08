// class Solution {
// public:
//     vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
//         int maxK= (1<<maximumBit)-1;
//         // vector<vector<int>>sets;
//         vector<int>v(22,0);
//         for(auto&i:nums){
//             for(int j=0;j<22;++j){
//                if(i&(1<<j)){
//                 ++v[j];
//                }
//             }
//         }
//         vector<int>ans;
//         while(!nums.empty()){
//             int c=0;
//             for(int j=0;j<22;++j){
//                 if((v[j]&1) || ((1<<j)<=maxK)) c|=(1<<j);
//                 // else if() c|=(1<<j);
//             }
//             int val=nums.back();
//              for(int j=0;j<22;++j){
//                if(val&(1<<j)){
//                 --v[j];
//                }
//             }
//             nums.pop_back();
//             ans.push_back(c);
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxK = (1 << maximumBit) - 1;
        int cumulativeXor = 0;
        vector<int> ans;

        // Calculate the XOR for all elements in nums initially
        for (int i : nums) {
            cumulativeXor ^= i;
        }

        // For each element from the back, calculate the maximum XOR
        for (int i = nums.size() - 1; i >= 0; --i) {
            // XOR with maxK to get maximum possible XOR with maximumBit bits
            ans.push_back(cumulativeXor ^ maxK);
            // Remove the last element from cumulativeXor
            cumulativeXor ^= nums[i];
        }

        return ans;
    }
};
