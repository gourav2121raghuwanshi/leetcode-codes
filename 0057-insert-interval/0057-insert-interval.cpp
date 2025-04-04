class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {newInterval};
        vector<int>curr=intervals[0];
         vector<vector<int>>ans;
        for(int i=0;i<intervals.size();++i){
            if(intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            }else if(intervals[i][0]>newInterval[1]){
                ans.push_back(newInterval);
                newInterval=intervals[i];
            }else{
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        ans.push_back(newInterval);

         return ans;
    }
};