class Solution  {
    bool isVal(int mid,vector<int>& weights, int days){
        int dc=1;
        int sm=0;
        for(int i=0;i<weights.size();++i){
            if(weights[i]>mid) return false;
            if(weights[i]+sm<=mid){
                sm+=weights[i];
            }else{
                // cout<<sm<<endl;
                ++dc;
                sm=weights[i];
            }
            if(dc>days) return false;
        }
        cout<<mid<<" "<<dc<<endl;
        return dc<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int s=0;
       int ans=-1;
       int e=accumulate(weights.begin(),weights.end(),0);
       while(s<=e) {
        int mid=(s+e)/2;
        if(isVal(mid,weights,days)){
            ans=mid;
            e=mid-1;
        }else s=mid+1;
       }
       return ans;
    }
};