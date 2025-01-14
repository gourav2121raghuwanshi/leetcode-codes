class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        int c=0;
        vector<int>f1(51,0),f2(51,0);
        for(int i=0;i<A.size();++i){
            ++f1[A[i]];
            ++f2[B[i]];
            c=0;
            for(int i=0;i<51;++i){
                if(f1[i] && f2[i]) ++c;
            }
            ans.push_back(c);
        }

        return ans;
    }
};