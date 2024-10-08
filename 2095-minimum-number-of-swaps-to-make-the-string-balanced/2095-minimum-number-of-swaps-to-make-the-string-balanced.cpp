class Solution {
public:
    int minSwaps(string s) {
         int maxi=0;
         int c=0;
         for(auto&i:s){
            if(i==']') ++c;
            else --c;
            maxi=max(maxi,c);
         }
        return ceil(maxi*1.0/2);
    }
};