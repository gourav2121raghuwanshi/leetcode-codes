class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==1) return nums;
        deque<int>dq;
        for(int i=0;i<k;++i){
            while(!dq.empty() && nums[dq.front()]<=nums[i]) dq.pop_front();
            while(!dq.empty() &&  nums[dq.back()]<=nums[i]) dq.pop_back();
           
            dq.push_back(i);
        }
        vector<int>ans;
        for(int i=k;i<nums.size();++i){
             ans.push_back(nums[dq.front()]);
             while(!dq.empty() && (nums[dq.front()]<=nums[i] || dq.front()<=i-k)) dq.pop_front();
             while(!dq.empty() &&  nums[dq.back()]<=nums[i]) dq.pop_back();
              dq.push_back(i);
        }
          ans.push_back(nums[dq.front()]);
           
        return ans;
    }
};