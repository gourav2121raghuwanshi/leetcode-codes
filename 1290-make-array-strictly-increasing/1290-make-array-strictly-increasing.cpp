class Solution {
    map<pair<int,int>,int>mp;
    int solve(int idx,int prev,vector<int>& arr1, vector<int>& arr2){
        if(idx>=arr1.size()) return 0;
        if(mp.count({idx,prev})) return mp[{idx,prev}];
        int result1=1e9;
        if(arr1[idx]>prev)  result1=solve(idx+1,arr1[idx],arr1,arr2);
        int result2=1e9;
        auto ub=upper_bound(arr2.begin(),arr2.end(),prev);
        if(ub!=arr2.end()){
            int i=ub-arr2.begin();
            int temp=solve(idx+1,arr2[i],arr1,arr2);
            if(temp!=1e9)
            result2=1+temp;
        }
        return  mp[{idx,prev}] = min(result2,result1);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int ans= solve(0,-1,arr1,arr2);
        return ans==1e9?-1:ans;
    }
};