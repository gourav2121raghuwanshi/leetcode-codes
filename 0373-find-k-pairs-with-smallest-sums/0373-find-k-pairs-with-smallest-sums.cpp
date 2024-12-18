class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         vector<vector<int>>ans;
         set<pair<int,int>>st;
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
         pq.push({nums1[0]+nums2[0],{0,0}});
         st.insert({0,0});
         int n=nums1.size();
         int m=nums2.size();
         while(k--){
            auto front=pq.top();
            pq.pop();
            int idx1=front.second.first;
            int idx2=front.second.second;
            ans.push_back({nums1[idx1],nums2[idx2]});
            if(idx1+1<n && !st.count({idx1+1,idx2})){
                st.insert({idx1+1,idx2});
                pq.push({nums1[idx1+1]+nums2[idx2],{idx1+1,idx2}});
            }
            if(idx2+1<m && !st.count({idx1,idx2+1})){
                st.insert({idx1,idx2+1});
                pq.push({nums1[idx1]+nums2[idx2+1],{idx1,idx2+1}});
            }
         }
         return ans;
    }
};