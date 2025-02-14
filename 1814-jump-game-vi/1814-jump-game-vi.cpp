class Solution {
    // video : https://www.youtube.com/watch?v=W8N8EeWDwKs
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        int ans;
        for(int i=n-1;i>=0;--i){
                while(!pq.empty() && pq.top().second>i+k) pq.pop();

                if(!pq.empty()){
                    if(i==0) ans=pq.top().first+nums[i];
                    pq.push({pq.top().first+nums[i],i});
                }else{
                    if(i==0) ans=nums[i];
                    pq.push({nums[i],i});
                }
        }
        return ans;
    }
};