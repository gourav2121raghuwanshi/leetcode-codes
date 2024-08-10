class Solution {
public:
int pivot(vector<int>&arr,int l,int r){
        int pe=arr[r];
        int i=l-1;
        for(int j=l;j<r;j++){
            if(arr[j]<pe){
                ++i;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return i+1;
    }
    int kthSmallest(vector<int>&arr, int l, int r, int k) {
       
       int pe=pivot(arr,l,r);
       if(k-1==pe-l){
           return arr[pe];
       }else if(k-1<pe-l){
           return kthSmallest(arr,l,pe-1,k);
       }else{
           return kthSmallest(arr,pe+1,r,k-(pe-l+1));
       }
       
    }
    int findKthLargest(vector<int>& nums, int k) {
        return kthSmallest(nums,0,nums.size()-1,nums.size()-k+1);
    }
};