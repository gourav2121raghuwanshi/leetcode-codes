class Solution {
    int req;
    string ans;
    bool solve(unordered_set<string>st,string &s){
        if(s.size()==req){
            if(!st.count(s)){
                ans=s;
                return 1;
            }
            return 0;
        }
        s.push_back('0');
        if(solve(st,s)) return 1;
        s.pop_back();
        s.push_back('1');
        if(solve(st,s)) return 1;
        s.pop_back();

        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        req=nums[0].size();
        string s;
        unordered_set<string>st(nums.begin(),nums.end());
        solve(st,s);
        return ans;
    }
};