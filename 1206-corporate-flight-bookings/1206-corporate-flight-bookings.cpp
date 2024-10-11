class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n+1);
        // logic : passengers l pe aa jayenge , and r+1 pe utar jayenge
        for(auto&i:bookings){
            int l=i[0];
            int r=i[1];
            int val=i[2];
            ans[l]+=val;
            if(r+1<=n)
            ans[r+1]-=val;
        }
        for(int i=1;i<ans.size();++i){
            ans[i]+=ans[i-1];
            ans[i-1]=ans[i];
        }
        ans.pop_back();
        return ans;
    }
};