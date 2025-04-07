class Solution {
public:
    double myPow(double x, int exp) {
        if(x==1) return 1;
        double ans=1;
        long long n=exp;
        bool f=false;
        if(n<0){
            f=true;
            n= -n;
            x=1/x;
        }

        while(n>0){
            if(n&1){
                ans=ans*x;
            }
                n/=2;
                x*=x;
        
        }


       return ans;
    }
};