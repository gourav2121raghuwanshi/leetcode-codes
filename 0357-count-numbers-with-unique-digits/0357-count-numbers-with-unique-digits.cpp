class Solution {
   
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n<=0) return 1;
        // approach : use p & c 
        // for 1 digit number : 10 (0 to 10) [10 choices]
        // for 2 digit number : 9 choices[1 to 9] * 9 choices[0 added and 1 dig gone] + (answer for 1 digit number)
        // for 3 dig : 9*9*8+ (2 digit answer) + ( 1 digit answer)
        //  and so on
        int ans=10;
        int dig=9;
        int curr=9;
        while(n>1){
            curr= curr*(dig--);
            ans+=(curr);
            --n;
        }

        return ans;
    }
};