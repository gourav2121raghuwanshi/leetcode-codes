class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n+2,0);
        for(auto&i:bookings){
            ans[i[0]]+=i[2];
            ans[i[1]+1]-=i[2];
        }
        vector<int>v;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=ans[i];
            v.push_back(sum);
        }
        return v;
        
    }
};