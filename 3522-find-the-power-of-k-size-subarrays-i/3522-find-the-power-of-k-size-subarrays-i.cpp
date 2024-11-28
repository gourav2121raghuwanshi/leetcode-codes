class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int cnt=1; // count corrent elements in current window
        if(k==1) return nums;
        for(int i=1;i<k;i++){
            if(nums[i-1]+1==nums[i]) ++cnt;
        }
        vector<int>ans;
        if(cnt==k) ans.push_back(nums[k-1]);
        else ans.push_back(-1);
        for(int i=k;i<nums.size();++i){
            if(nums[i-k]+1==nums[i-k+1]) --cnt;
             if(nums[i-1]+1==nums[i]) ++cnt;
              if(cnt==k) ans.push_back(nums[i]);
              else ans.push_back(-1);
       
        }
        
        return ans;
    }
};