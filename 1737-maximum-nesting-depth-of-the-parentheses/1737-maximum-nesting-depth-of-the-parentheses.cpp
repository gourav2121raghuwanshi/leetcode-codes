class Solution {
public:
    int maxDepth(string s) {
        int sp=0;
        int ans=0;
        for(auto&i:s){
            if(i=='(') ++sp;
            else if(i==')') --sp;
            ans=max(ans,sp);
        }
        return ans;
    }
};