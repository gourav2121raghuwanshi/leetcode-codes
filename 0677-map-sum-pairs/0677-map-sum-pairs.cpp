class MapSum {
public:
    unordered_map<string,int>mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
            mp[key]=val; 
    }
    
    int sum(string prefix) {
        int len=prefix.size();
        int ans=0;
        for(auto&i:mp){
            string s=i.first;
            int val=i.second;
            if(s.size()>=prefix.size() && s.substr(0,len)==prefix){
                ans+=val;
            }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */