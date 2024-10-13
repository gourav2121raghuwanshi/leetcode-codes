class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=nums.size();
        int maxi=-1e9,mini=1e9;
        for(int i=0;i<n;++i){
            pq.push({nums[i][0],{i,0}});
            maxi=max(maxi,nums[i][0]);
            mini=min(mini,nums[i][0]);
        }
        int ansEnd=maxi;
        int ansstart=mini;
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int ele=front.first;
            int row=front.second.first;
            int index=front.second.second;
            mini=ele;
            if(ansEnd-ansstart>maxi-mini){
                ansstart=mini;
                ansEnd=maxi;
            }
            if(index+1>=nums[row].size()) return {ansstart,ansEnd};

            pq.push({nums[row][index+1],{row,index+1}});
            // whenever insert a  new value update maximum
            maxi=max(maxi,nums[row][index+1]);
            

        }return {ansstart,ansEnd};
    }
};