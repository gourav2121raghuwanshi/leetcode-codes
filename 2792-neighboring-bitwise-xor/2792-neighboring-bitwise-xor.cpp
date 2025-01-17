class Solution {
    bool check(vector<int>&a,vector<int>&b){
        int n=a.size();
        for(int i=0;i<n-1;i++){
            if((a[i]^a[i+1])!=b[i]){
                return false;
            }
        }
        if((a[0]^a[n-1])!=b[n-1]) return false;
        return true;
    }
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int>ans;
        ans.push_back(0);
        for(int i=0;i<n-1;i++){
            ans.push_back(ans.back()^derived[i]);
        }
        if(check(ans,derived)) return true;
        ans.clear();
        ans.push_back(1);
        for(int i=0;i<n-1;i++){
            ans.push_back(ans.back()^derived[i]);
        }
        if(check(ans,derived)) return true;

        return false;
    }
};