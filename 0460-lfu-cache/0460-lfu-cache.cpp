
class LFUCache {

    int size;
    int c;
    map<int, list<vector<int>>> mp; // freq, {key,val,freq}
    unordered_map<int, list<vector<int>>::iterator> address; // key, pointer
public:
    LFUCache(int capacity) {
        size = capacity;
        c = 0;
    }

    int get(int key) {
        if (address.count(key)) {
            vector<int> v = *address[key];
            int val = v[1];
            int f = v[2];
            mp[f].erase(address[key]);
            if (mp[f].empty())
                mp.erase(f);
            ++f;
            v[2] = f;
            mp[f].push_front(v);
            address[key] = mp[f].begin();
            return val;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (size == 0)
            return;

        if (address.count(key)) {
            vector<int> v = *address[key];
            int val = v[1];
            int f = v[2];
            mp[f].erase(address[key]);
            if (mp[f].empty())
                mp.erase(f);
            ++f;
            v[2] = f;
            v[1] = value;
            mp[f].push_front(v);
            address[key] = mp[f].begin();
        } else {
            if (c + 1 <= size) {
                ++c;
                vector<int> v = {key, value, 1};
                mp[1].push_front(v);
                address[key] = mp[1].begin();
            } else {
                auto& to_delete = mp.begin()->second;
                int f = to_delete.back()[2];
                int v = to_delete.back()[1];
                int k = to_delete.back()[0];
                mp[f].erase(address[k]);

                if (mp[f].empty())
                    mp.erase(f);
                address.erase(k);
                vector<int> vv = {key, value, 1};
                mp[1].push_front(vv);
                address[key] = mp[1].begin();
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */