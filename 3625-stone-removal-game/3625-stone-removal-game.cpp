class Solution {
public:
    bool canAliceWin(int n) {
        int i=10;
        bool turn=1;
        // 1: alice , 0 bob
        while(n>=i){
            n-=i;
            i-=1;
            turn=1-turn;
        }
        if(turn) return false;
        return true;
    }
};