class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto&i:nums)  v.push_back(to_string(i));
        sort(v.begin(),v.end(),[](string aa,string bb){
            return aa+bb>bb+aa;
        });
        for(auto&i:v) cout<<i<<" ,";
        string ans="";

        for(auto &i:v){
            if(ans.empty() && i=="0") continue;
             ans+=i;
             }

        // while(!ans.empty() && ans.back()=='0')
        // ans.pop_back();

        if(ans.empty()) return "0";
        // reverse(ans.begin(),ans.end());
        return ans;

    }
};