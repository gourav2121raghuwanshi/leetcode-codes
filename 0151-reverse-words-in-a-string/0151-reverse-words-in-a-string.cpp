class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i=0;
        string temp;
        while(i<s.size()){
            if(s[i]==' '){
                if(!temp.empty()){
                    if(ans.empty()) ans=temp;
                    else 
                    ans=temp+" "+ans;
                    temp="";
                }
                ++i;
            }else{
                temp.push_back(s[i]);
                ++i;
            }
        }
         if(!temp.empty()){
                    if(ans.empty()) ans=temp;
                    else 
                    ans=temp+" "+ans;
                }
        return ans;
    }
};