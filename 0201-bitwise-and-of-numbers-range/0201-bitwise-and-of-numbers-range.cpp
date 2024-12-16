class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cbit1 = 0;
        int cbit2 = 0;
        for (int i = 0; i < 32; i++) {
            if (left & (1 << i))
                cbit1 = i;
            if (right & (1 << i))
                cbit2 = i;
        }
        if (cbit2 != cbit1)
            return 0;
        while(right>left){
            right = right&(right-1);
        }
        return right;
    }
};