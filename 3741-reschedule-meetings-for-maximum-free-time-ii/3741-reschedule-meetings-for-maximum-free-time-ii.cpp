class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>pref,suff;
        vector<int>gap;
        int ans=0;
        gap.push_back(startTime[0]);
        ans=max(ans,gap.back());
        for(int i=0;i<startTime.size()-1;++i){
            gap.push_back(startTime[i+1]-endTime[i]);
            ans=max(ans,gap.back());
        }
        gap.push_back(eventTime-endTime.back());
        ans=max(ans,gap.back());
        int maxi=-1;
        for(int i=0;i<gap.size()-1;++i){
            pref.push_back(maxi);
            maxi=max(maxi,gap[i]);
        }
        suff.resize(n);
        maxi=-1;
        for(int i=gap.size()-1;i>0;--i){
            suff[i-1]=maxi; 
            maxi=max(maxi,gap[i]);
        }

        for(int i=0;i<n;++i){
            int len=endTime[i]-startTime[i];
            if(pref[i]>=len || suff[i]>=len)
            ans=max(ans,len+gap[i]+gap[i+1]);
        }

        for(int i=0;i<gap.size()-1;i++){
                ans=max(ans,gap[i]+gap[i+1]);
        }

        return ans;
    }
};