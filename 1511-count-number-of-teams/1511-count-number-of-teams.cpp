class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;

        for(int i=0;i<rating.size();++i){
            int ls=0,ll=0;
            int rs=0,rl=0;
            for(int j=0;j<i;++j){
                if(rating[j]<rating[i]) ++ls;
                else if(rating[j]>rating[i]) ++ll;
            }
            for(int j=i+1;j<rating.size();++j){
                if(rating[j]<rating[i]) ++rs;
                else if(rating[j]>rating[i]) ++rl;
            }
            ans+=(ls*rl)+(ll*rs);
        }

        return ans;
    }
};