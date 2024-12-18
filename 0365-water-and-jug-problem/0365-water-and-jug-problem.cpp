class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target) return 0;
        int gc=__gcd(x,y);
        return target%gc==0;
    }
};