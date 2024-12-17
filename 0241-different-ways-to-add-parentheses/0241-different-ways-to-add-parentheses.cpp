class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
       
        vector<int>ans;
        int val=0;
        for(int i=0;i<expression.size();++i){
            if(expression[i]=='-' || expression[i]=='*' || expression[i]=='+'){
                vector<int>left=diffWaysToCompute(expression.substr(0,i));
                vector<int>right=diffWaysToCompute(expression.substr(i+1));
                for(auto&ii:left){
                    for(auto&jj:right){
                        if(expression[i]=='+')
                        ans.push_back(ii+jj);
                        else if(expression[i]=='-') ans.push_back(ii-jj);
                        else ans.push_back(ii*jj);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return ans;
    }
};