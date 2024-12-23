class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        for(int i=0;i<customers.size();++i){
            if(grumpy[i]==0) ans+=customers[i];
        }

        int sum=0;
        for(int i=0;i<min((int)customers.size(),minutes);++i){
            if(grumpy[i]==1) sum+=customers[i];
        }
        int maxi=sum;
        int s=0;
        for(int i=minutes;i<customers.size();++i){
            if(grumpy[i-minutes]==1) sum-=customers[i-minutes];
            if(grumpy[i]==1) sum+=customers[i];
            ++s;
            maxi=max(maxi,sum);
        }
        return maxi+ans;
    }
};