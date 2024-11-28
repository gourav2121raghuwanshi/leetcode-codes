class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int>dq; // indices in increasing order
        vector<long long>cumu(nums.size());
        int ans=INT_MAX;
        int j=0;
        int n=nums.size();
        while(j<n){
            if(j==0){
                cumu[j]=nums[j];
            }else{
                cumu[j]=cumu[j-1]+nums[j];
            }
            if(cumu[j]>=k){
                ans=min(ans,j+1);
            }
            while(!dq.empty() && cumu[j]-cumu[dq.front()]>=k){
                ans=min(ans,j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && cumu[j]<=cumu[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            ++j;
        }
        return ans==INT_MAX?-1:ans;
    }
};