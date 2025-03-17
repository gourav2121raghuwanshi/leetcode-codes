class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int arr[501];
        memset(arr,0,sizeof(arr));
        for(auto&i:nums){
            ++arr[i];
        }
        for(auto&i:arr){
            if(i&1)return false;
        }
        return true;
    }
};