class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int j=0;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(j<spaces.size() && i==spaces[j]){
                // if(temp.empty())
                // ans+= " ";
                // else if(!temp.empty()){
                //     if(j==0) ans+=temp;
                //     else
                    ans+=" " +temp;
                    // else ans=temp;
                // }
                temp.clear();
                ++j;
                temp.push_back(s[i]);
            }else temp.push_back(s[i]);
        }
        if(!temp.empty())  ans+= " " +temp;
        if(!ans.empty())
        ans.erase(0,1);
        return ans;
    }
};