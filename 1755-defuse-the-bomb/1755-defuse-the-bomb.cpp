class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans;
        int take=1;
        if(k<0) take=-1;
        // cout<<take<<endl;
        int n=code.size();
        k=abs(k);
        for(int i=0;i<code.size();++i){
            int sm=0;
            if(k==0){
                ans.push_back(0);
                continue;
            }
            int idx=(i+take+n)%n;
            for(int j=0;j<k;++j){
                // cout<<code[idx]<<" ,"<<endl;
                sm+=code[idx];
                idx=(idx+take+n)%n;
            }
            ans.push_back(sm);
        }
        return ans;
    }
};