class StockPrice {
    // int mini=INT_MAX;
    // int maxi=0;
    int maxTime=0;
    int mtp=0;
    unordered_map<int,int>mp;
    multiset<int>st;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)){
            st.erase(st.find(mp[timestamp]));
        }
        if(maxTime<=timestamp){
            mtp=price;
            maxTime=timestamp;
        }
            mp[timestamp]=price;
            st.insert(price);  
    }
    
    int current() {
        return mtp;
    }
    
    int maximum() {
        auto it=st.end();
        --it;
        return *it;
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */