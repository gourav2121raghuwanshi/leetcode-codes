class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // unordered_set<int>valid;
        unordered_map<int,int>valid;

        unordered_set<char>vowel={
            'a','e','i','o','u'
        };
        int c=0;
        for(int j=0;j<words.size();++j){
            string i=words[j];
            if(vowel.count(i[0]) && vowel.count(i[i.size()-1])){
                ++c;
               valid[j]=c;
            }else valid[j]=c;
        }
        vector<int>ans;
        for(auto&i:queries){
            int start=i[0];
            int end=i[1];
            cout<<valid[start]<<" , "<<valid[end]<<endl;
            if(!valid.count(start-1))
            ans.push_back(valid[end]);
            else
            ans.push_back(valid[end]-valid[start-1]);
        }
        return ans;
    }
};