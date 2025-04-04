class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;++i){
            sum+=cardPoints[i];
        }
        int ans=sum;
        int j=k-1;
        int i=cardPoints.size()-1;
        while(j>=0){
            sum-=cardPoints[j--];
            sum+=cardPoints[i--];
            ans=max(ans,sum);
        }
        return ans;
    }
};