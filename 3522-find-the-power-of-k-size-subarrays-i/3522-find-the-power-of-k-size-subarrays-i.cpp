class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
       vector<int>ans;
       int n=nums.size();
       for(int i=0;i<=n-k;i++) {
        bool f=true;
        for(int j=i;j<i+k;j++){
            if(j==i) continue;
            else if(nums[j]<=nums[j-1] || nums[j-1]+1!=nums[j]){
                f=false;
                break;
            }
        }
        if(f) ans.push_back(nums[i+k-1]);
        else ans.push_back(-1);
       }
       return ans;
    }
};