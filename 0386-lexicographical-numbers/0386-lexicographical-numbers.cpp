class Solution {
    vector<int>ans;
    void solve(int i,int n){
        if(i>n) return;
        ans.push_back(i);
        for(int j=0;j<=9;++j){
            solve(i*10+j,n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        
        for(int i=1;i<=9;++i){
            solve(i,n);
        }
        return ans;
    }
};