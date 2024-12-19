class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int ans=0;
        while(i<n){
            ++ans;
            int maxi=arr[i];
            int idx=i;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]<maxi){
                    idx=j;
                }
                for(int k=i;k<=idx;k++) maxi=max(maxi,arr[k]);
            }
            i=idx+1;
        }
        return ans;
    }
};