class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo=0;
        for(auto&i:nums) xo^=i;
        int c=0;
        while(xo){
            if(xo&1) break;
            ++c;
            xo/=2;
        }
        int a=0;
        int b=0;
        for(auto&i:nums){
            if(i&(1<<c)) a^=i;
            else b^=i;
        }
        return {a,b};
    }
};