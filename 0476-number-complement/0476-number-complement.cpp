class Solution {
public:
    int findComplement(int num) {
        int comp=0;
        int c=0;
        while(num){
            int a=(num%2);
            num>>=1;
            // cout<<a<<" "<<c<<endl;
            if(!a){
                comp |= (1<<c);
            }
            ++c;
        }
        return comp;
    }
};