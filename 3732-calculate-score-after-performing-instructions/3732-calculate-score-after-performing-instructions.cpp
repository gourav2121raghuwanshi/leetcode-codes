class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long ans=0;
        unordered_set<int>st;
        int i=0;
        int n=instructions.size();
        while(i>=0 && i<n){
            if(st.count(i)) break;
            if(instructions[i]=="add"){
                ans+=values[i];
                st.insert(i);
                ++i;
            }else{
                st.insert(i);
                i=i+values[i];
            }
        }
        return ans;
    }
};