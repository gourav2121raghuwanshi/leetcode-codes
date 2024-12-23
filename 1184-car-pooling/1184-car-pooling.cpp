class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<trips.size();i++){
            int currStart=trips[i][1];
            while(!pq.empty() && pq.top().first<=currStart){
                capacity+=pq.top().second;
                pq.pop();
            }
            if(trips[i][0]>capacity) return false;
            capacity-=trips[i][0];
            pq.push({trips[i][2],trips[i][0]});
        }
        return true;
    }
};