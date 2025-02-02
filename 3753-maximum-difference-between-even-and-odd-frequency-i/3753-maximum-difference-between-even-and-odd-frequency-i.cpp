class Solution {
public:
    int maxDifference(string s) {
        vector<int>f(26,0);
        
        for(auto&i:s){
            ++f[i-'a'];
        }
        int omax=0;
        int omin=1e9;
        int emax=0;
        int emin=1e9;
        for(int i=0;i<26;i++){
            if(f[i]){
                if(f[i]&1) {
                    omax=max(f[i],omax);
                    omin=min(f[i],omin);
                }
                else {
                    emax=max(f[i],emax);
                    emin=min(f[i],emin);
                }
            }
        }
         int result = INT_MIN;
        if (omax != -1 && emin != 1e9) {
            result = max(result, omax - emin);
        }
        if (omin != 1e9 && emax != -1) {
            result = max(result, omin - emax);
        }

        return  result; 
        
    }
};