class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int>flexible;
        stack<int>openIdx;

        int n=s.size();
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                flexible.push(i);
            }else if(s[i]=='('){
                openIdx.push(i);
            }else{
                if(!openIdx.empty()) openIdx.pop();
                else if(!flexible.empty())flexible.pop();
                else return false;
            }
        }
        while(!flexible.empty() && !openIdx.empty()){
            if(openIdx.top()<flexible.top()){
                flexible.pop();
                openIdx.pop();
            }else break;
        }
    if(!flexible.empty() && openIdx.empty()){
        return flexible.size()%2==0;
    }
        return openIdx.empty();
    }
};