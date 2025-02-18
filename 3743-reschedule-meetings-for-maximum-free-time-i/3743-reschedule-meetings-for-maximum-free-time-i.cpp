class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>gap;
        gap.push_back(startTime[0]);
        for(int i=0;i<startTime.size()-1;++i){
            gap.push_back(startTime[i+1]-endTime[i]);
        }
        gap.push_back(eventTime-endTime.back());
        int s=0;
        int ans=0;
        int sum=0;
        for(int i=0;i<gap.size();++i){
            sum+=gap[i];
            if(i-k-1>=0) sum-=gap[i-k-1];
            ans=max(ans,sum);
        }
        return ans;
    }
};