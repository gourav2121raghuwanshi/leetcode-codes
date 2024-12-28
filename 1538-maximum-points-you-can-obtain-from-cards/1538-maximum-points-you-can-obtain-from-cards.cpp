class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int sum=0;
        int maxi=0;

        int n=card.size();
        for(int i=0;i<min(k,n);++i) sum+=card[i];
        maxi=sum;
        if(k>=n) return maxi;

        int j=n-1;
        int i=k-1;
        for(int i=k-1;i>=0;--i){
            sum-=card[i];
            sum+=card[j--];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};