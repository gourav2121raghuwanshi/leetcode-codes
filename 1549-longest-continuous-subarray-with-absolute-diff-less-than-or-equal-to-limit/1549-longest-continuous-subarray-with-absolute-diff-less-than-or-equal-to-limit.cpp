class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        int n=nums.size();
        int s=0;
        deque<int>small,large;
        for(int i=0;i<n;++i){
            while(!small.empty() && small.back()>nums[i]){
                small.pop_back();
            }
            while(!large.empty() && large.back()<nums[i]){
                large.pop_back();
            }
            small.push_back(nums[i]);
            large.push_back(nums[i]);

            while(!small.empty() && !large.empty() && large.front()-small.front()>limit){
                if(small.front()==nums[s]){
                    small.pop_front();
                }
                if(large.front()==nums[s]){
                    large.pop_front();
                }
                ++s;
            }
            ans=max(ans,i-s+1);
        }

        return ans;
    }
};