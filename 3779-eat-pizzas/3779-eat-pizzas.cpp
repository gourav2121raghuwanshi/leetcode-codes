class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        //  1,2,2,   2,2,  3  ,3,3,   4,4,
        // 3 days
        // day 1 and day 3 -> Last
        // day 2 ->second last
        // 1: (1,2,2,5)
        // 2: (2,2,4,4)
        // 3: (3,3,3,5)
        int n=pizzas.size();
        int totalMoves=n/4;
        int odd=(totalMoves+1)/2;
        int even=totalMoves-odd;
        long long ans=0;
        int i=3*odd;
        sort(pizzas.begin(),pizzas.end());
        while(odd--){
            ans+=1LL*pizzas.back();
            pizzas.pop_back();
        }
        i=pizzas.size()-1;
        while(even--){
            --i;
            ans+=1LL*pizzas[i];
            --i;
        }
        return ans;

    }
};