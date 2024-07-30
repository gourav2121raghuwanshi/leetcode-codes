class Solution {
public:
    int minimumDeletions(string s) {
        // at every index what is cost of making 
        // all prev values  including itself as 'a'
        // all next values after it as 'b'
        // aaabb
        // a=1, b=0
        int n=s.size();
        // int ans=n;
        int totalOne=0,totalZero=0;
        for(auto&i:s){
            if(i=='a') ++totalOne;
            else ++totalZero;
        }
    if(totalZero==0 || totalOne==0) return 0;
     int ans = min(totalZero,totalOne);

        int oc=0;
        int zc=0;
        for(auto&i:s){
             if(i=='a') ++oc;
            else ++zc;
            ans=min(ans,zc+totalOne-oc);
           
            
        }

        return ans;
    }
};
// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n = s.size();
        
//         int totalOne = 0, totalZero = 0;

//         // Count total 'a's and 'b's
//         for (char c : s) {
//             if (c == 'a') ++totalOne;
//             else ++totalZero;
//         }

       
//         if (totalZero == 0 || totalOne == 0) return 0;
//         int ans = min(totalZero,totalOne);
//         int oc = 0; // Number of 'a's so far
//         int zc = 0; // Number of 'b's so far

//         for (char c : s) {
//             if (c == 'a') ++oc;
//             else ++zc;
            
//             // Calculate minimum deletions
//             ans = min(ans, zc + totalOne - oc);
//         }

//         return ans;
//     }
// };
