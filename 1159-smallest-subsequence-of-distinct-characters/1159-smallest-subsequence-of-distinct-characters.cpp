class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>freq(26,0),taken(26,0);
        for(auto&i:s){
            ++freq[i-'a'];
        }
        string ans;

        for(auto&i:s){
            --freq[i-'a'];
            if(taken[i-'a']){
                continue;
            }else{
            while(!ans.empty() && ans.back()>=i && freq[ans.back()-'a']){ taken[ans.back()-'a']=0; ans.pop_back(); }
            taken[i-'a']=1;
            ans.push_back(i);}
        }
        return ans;
    }
};