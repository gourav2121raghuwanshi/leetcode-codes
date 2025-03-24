class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // sort(meetings.begin(),meetings.end(),[](const vector<int>&a,const vector<int>&b){
        //     if(a[1]!=b[1])
        //     return a[1]>b[1];
        //     else return a[0]<b[0];
        // });
        int ans=0;
        map<int,int>mp;
        int j=1;
        for(auto&i:meetings){
            mp[i[0]]+=j;
            mp[i[1]]-=j;
            ++j;
        }
        int prev=1;
        long long csum=0;
        int c=0;
        for(auto&i:mp){
            cout<<i.first<<" , "<<i.second<<endl;
            if(csum==0){
                if(c==0) ans+=i.first-prev;
                else if(i.first!=prev)
                ans+=(i.first-prev-1);
            }
            csum+=i.second;
            prev=i.first;
            ++c;
        }
        if(days!=prev)
        ans+=days-prev;
        return ans;
    }
};