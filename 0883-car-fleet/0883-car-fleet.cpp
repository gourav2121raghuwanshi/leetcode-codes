class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      vector<pair<int,int>>v;
      for(int i=0;i<speed.size();++i){
        v.push_back({position[i],speed[i]});
      }

        sort(v.rbegin(),v.rend());

        stack<double>st;
        for(auto&i:v){
            double time = (target-i.first)*1.0/i.second;
            if(st.empty() || st.top()<time) st.push(time);
            else continue;
        }

        return st.size();
    }
};