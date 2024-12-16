class Solution {
    void count_sort(vector<int>& v, int pos) {
        int n = v.size();
        // max

        // frequecy
        vector<int> freq(10, 0);
        for (int i = 0; i < n; i++) {
            freq[(v[i] / pos) % 10]++;
        }
        // cumulative freq
        for (int i = 1; i < 10; i++) {
            freq[i] += freq[i - 1];
        }
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[--freq[(v[i] / pos) % 10]] = v[i];
        }
        for (int i = 0; i < n; i++) {
            v[i] = ans[i];
        }
        return;
    }

public:
    int maximumGap(vector<int>& v) {
        int n = v.size();
        if(n==1) return 0;
        if(n==2) return abs(v[0]-v[1]);
        int maxi = INT32_MIN;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > maxi) {
                maxi= v[i];
            }
        }
        int pos=1;
        while(pos<=maxi){
            count_sort(v,pos);
            pos*=10;
        }
       int maxDiff=INT_MIN;
       for(int i=1;i<n;++i){
        maxDiff=max((int)(v[i]-v[i-1]),maxDiff);
       }
       return maxDiff;
    }
};