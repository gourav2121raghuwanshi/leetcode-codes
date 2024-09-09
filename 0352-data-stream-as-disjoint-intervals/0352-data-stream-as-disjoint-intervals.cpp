class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    // vector<int>v;
    set<int>st;
    void addNum(int value) {
        // v.push_back(value);
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        vector<int>temp;
        // int prev=v[0];
        // temp.push_back(prev);
        int prev=-1;
        for(auto&i:st){
            if(prev==-1){
                prev=i;
                temp.push_back(i);
            }else if(i-1==prev){
                prev=i;
                continue;
            }else{
                temp.push_back(prev);
                ans.push_back(temp);
                temp.clear();
                temp.push_back(i);
                prev=i;
            }
            prev=i;
        }
        // if(temp.empty()){
        //     ans.push_back({prev,prev});
        // }else{
            if(prev==-1) return ans;
            temp.push_back(prev);
            ans.push_back(temp);
        // }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */