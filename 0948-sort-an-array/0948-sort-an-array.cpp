class Solution {
    void heapify(vector<int>& nums,int idx,int n){
        int i=idx;
        int left=2*idx+1;
        int right=2*idx+2;
        if(left<n && nums[idx]<nums[left]) i=left;
        if(right<n && nums[i]<nums[right]) i=right;
        if(idx!=i){
            swap(nums[idx],nums[i]);
            heapify(nums,i,n);
        }
    }
    void buildHeap(vector<int>&nums){
        int n=nums.size();
        for(int i=n/2;i>=0;--i){
            heapify(nums,i,nums.size());
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();
        buildHeap(nums);
        for(int i=n-1;i>=0;--i){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
        return nums;
    }
};