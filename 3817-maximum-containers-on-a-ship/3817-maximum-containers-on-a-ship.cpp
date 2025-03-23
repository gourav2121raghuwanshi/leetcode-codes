class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int blocks=n*n;
        long long ans=0;
        long long wt=0;
        while(wt+w<=maxWeight && ans<blocks){
            wt+=w;
            ++ans;
        }
        return ans;
    }
};