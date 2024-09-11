class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c=0;
      for(int i=0;i<32;++i) {
        int x=((start>>i)&1);
        int y=((goal>>i)&1);
        c+=(x!=y);
      } 
      return c;
    }
};