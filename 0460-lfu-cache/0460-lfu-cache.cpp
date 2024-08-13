class LFUCache {
public:
    map<int,list<vector<int>>>mp; //{ freq_cnt, key,value,freq_cnt}
    unordered_map<int,list<vector<int>>::iterator>address; //{key,address}
    int cap;
    int size;
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }                        
    
    void makeMostRecent(int key){
        auto&addrs=*address[key];
        int f=addrs[2];
        int v=addrs[1];
        mp[f].erase(address[key]);
        if(mp[f].empty()){
            mp.erase(f);
        }
        ++f;
        mp[f].push_front({key,v,f});
        address[key]=mp[f].begin();
    }
    int get(int key) {
        if(address.find(key)==address.end()) return -1;
        auto addrs=*address[key];
        int val=addrs[1];
        makeMostRecent(key);
        return val;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(address.find(key)!=address.end()){
            auto&addrs=*address[key];
            addrs[1]=value;
            makeMostRecent(key);
        }else{
            if(size==cap){
                auto &list_to_delete= mp.begin()->second;
                int key_to_del=list_to_delete.back()[0];
                list_to_delete.pop_back();
                address.erase(key_to_del);
                if(list_to_delete.empty()){
                    mp.erase(mp.begin()->first);
                }
               --size;
            }
            ++size;
            mp[1].push_front({key,value,1});
            address[key]=mp[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */