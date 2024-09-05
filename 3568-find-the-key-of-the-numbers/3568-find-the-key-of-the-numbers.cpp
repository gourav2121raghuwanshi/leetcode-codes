class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string a=to_string(num1);
        string b=to_string(num2);
        string c=to_string(num3);
        int n=min(a.size(),min(b.size(),c.size()));
        int m=max(a.size(),max(b.size(),c.size()));
        string ans;
        int i=a.size()-1;
        int j=b.size()-1;
        int k=c.size()-1;
        for(int d=0;d<n;d++){
            char ch=min(a[i--],min(b[j--],c[k--]));
            ans.push_back(ch);
        }
        while(ans.size()<m){
            ans.push_back('0');
        }
        reverse(ans.begin(),ans.end());
        return stoi(ans);
    }
};