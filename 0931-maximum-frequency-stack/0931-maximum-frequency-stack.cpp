class FreqStack {
private:
    class comp {
    public:
        bool operator()(const pair<int, pair<int, int>>& a,
                        const pair<int, pair<int, int>>& b) const {
            if (a.first != b.first)
                return a.first > b.first;

            return a.second.first > b.second.first;
        }
    };

public:
    using p = pair<int, pair<int, int>>; // frequency, when It come(c) , element
    int c = 1; // initial time // will be incremented each time a new ele come
    unordered_map<int, vector<int>>
        cvalues;                  // to store all c values of particular element
    unordered_map<int, int> freq; // current freq of ele
    set<p, comp> st;

public:
    FreqStack() {}

    void push(int val) {
        if (freq[val]>0) {
            int itsLastFreq = freq[val];
            int itsLastCvalue = cvalues[val].back();
            auto record = st.find({itsLastFreq, {itsLastCvalue, val}});
            if (record != st.end()) {
                st.erase(record);
            }

            st.insert({itsLastFreq + 1, {c, val}});
            freq[val]++;
            cvalues[val].push_back(c);
            ++c;
        } else {
            freq[val] = 1;
            cvalues[val].push_back(c);
            st.insert({1, {c, val}});
            ++c;
        }
    }

    int pop() {
        if(st.empty()) return -1;
        p front = *st.begin();  
        st.erase(st.begin());
        int frq = front.first;         
        int cval = front.second.first;
        int val = front.second.second; 
        cvalues[val].pop_back();
        freq[val]--;
        if (freq[val] > 0 && !cvalues[val].empty()) {
            int cv = cvalues[val].back();
            st.insert({freq[val], {cv, val}});
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */