class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0;
        int maxLeft=values[0]+0;
        for(int i=1;i<values.size();++i){
            ans=max(ans,maxLeft+values[i]-i);
            maxLeft=max(maxLeft,values[i]+i);
        }
        return ans;
    }
};