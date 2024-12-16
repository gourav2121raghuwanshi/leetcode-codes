class Solution {
     vector<vector<int>>ans;
     void solve(int n,int num,int sum,int k,vector<int>&v){
        if(sum==n && k==v.size()){
            ans.push_back(v);
            return;
        }
        if(sum>n || k<v.size()) return;

        for(int i=num;i<=9;++i){
                v.push_back(i);
                solve(n,i+1,sum+i,k,v);
                v.pop_back();
            
        }
     }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        solve(n,1,0,k,v);
        return ans;
    }
};