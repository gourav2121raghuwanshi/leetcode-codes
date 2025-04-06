class Solution {
    void solve(string s,int oc,int cc,vector<string>&ans){
        if(oc==0 && cc==0){
            ans.push_back(s);
            return;
        }
        if(oc>0)
        solve(s+"(",oc-1,cc,ans);
        if(oc<cc && cc>0){
        solve(s+")",oc,cc-1,ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // if open_cound< close_cound -> can use )
        vector<string>ans;
        solve("",n,n,ans);
        return ans;
    }
};