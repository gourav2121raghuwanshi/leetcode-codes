class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        for(int i=0;i<32;++i){
            int one = ((start>>i)&1);
            int two= ((goal>>i)&1);
            if(one == two) continue;
            else ++ans;
        }
        return ans;
    }
};