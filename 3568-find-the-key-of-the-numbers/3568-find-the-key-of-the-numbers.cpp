class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        int mul = 1;
        while (num1 && num2 && num3) {
            int r1 = num1 % 10;
            int r2 = num2 % 10;
            int r3 = num3 % 10;
            ans = min(r1, min(r2, r3)) * mul + ans;
            mul *= 10;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return ans;
    }
};