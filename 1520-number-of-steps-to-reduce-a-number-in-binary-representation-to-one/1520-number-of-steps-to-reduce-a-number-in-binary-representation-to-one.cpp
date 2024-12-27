class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s.size()>1){++ans;
            if(s.back()=='0') s.pop_back();
            else{
              int carry=1;
              s.back()='0';
              for(int i=s.size()-2;i>=0;--i){
                if(s[i]=='0'){
                    s[i]='1';
                    carry=0;
                    break;
                }else{
                    s[i]='0';
                    carry=1;
                }
              }
              if(carry) s="1"+s;
            }
        }
        return ans;
    }
};