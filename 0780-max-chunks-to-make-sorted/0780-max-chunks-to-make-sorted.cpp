class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // appraoch1      // logic :if at index i :
        //  prefMax(Not Include i) <= SuffMin(include i)
        //   (then chunk++ at index i)

        // approach2 : make array b=arr
        //  sort array b
        //  now take two prefix sums one for arr and one for b
        //  if at any index two sums becomes same (can make chunk at that index)

        int n = arr.size();
        int ans=0;
        vector<int>b=arr;
        sort(b.begin(),b.end());
        int suma=0;
        int sumb=0;
        for(int i=0;i<n;i++){
            suma+=arr[i];
            sumb+=b[i];
            if(suma==sumb) ++ans;
        }
        return ans;
    }
};