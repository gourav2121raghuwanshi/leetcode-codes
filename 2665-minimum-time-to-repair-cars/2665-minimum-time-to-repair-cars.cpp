class Solution {
    bool valid(long long mid,vector<int>& ranks, int cars){
        // mid -> time we have
        // rank * cars^2 = time we have (we need to find cars)
        long long count=0;

        for(auto&i:ranks){
            count+=sqrt(mid/i*1LL);
        }
        return count>=cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long s=0;
        long long e=1e14;
        long long ans=-1;

        while(s<=e){
            long long mid=s+(e-s)/2;
            if(valid(mid,ranks,cars)){
                ans=mid;
                e=mid-1;
            }else s=mid+1;
        }
        return ans;
    }
};