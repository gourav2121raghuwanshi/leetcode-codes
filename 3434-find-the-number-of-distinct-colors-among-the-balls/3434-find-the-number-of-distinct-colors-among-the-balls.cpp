class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       unordered_map<int,int>mp;
      unordered_map<int,int>col;
       vector<int>ans;

        for(auto&i:queries){
            int x=i[0];
            int y=i[1];
            if(mp.count(x)){
               col[mp[x]]--;
               if(col[mp[x]]==0){
                col.erase(mp[x]);
               }
            }
            mp[x]=y;
            col[y]++;
            ans.push_back(col.size());
        }
       return ans; 
    }
};