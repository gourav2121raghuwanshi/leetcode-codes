class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> a, b;
        stringstream ss(s1);
        string str;
        while (getline(ss, str, ' ')) {
            ++a[str];
        }
        stringstream ss1(s2);
   
        while (getline(ss1, str, ' ')) {
            ++b[str];
        }
        vector<string>ans;
        for(auto&i:a){
            if(i.second==1 && b[i.first]==0) ans.push_back(i.first);
        }
         for(auto&i:b){
            if(i.second==1 && a[i.first]==0) ans.push_back(i.first);
        }
        return ans;
    }
};