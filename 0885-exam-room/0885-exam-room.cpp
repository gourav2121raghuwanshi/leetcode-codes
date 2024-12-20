class ExamRoom {
    int size;
    set<int>st;
public:
    ExamRoom(int n) {
        size=n-1;
    }
    
    int seat() {
        if(st.empty()){
            st.insert(0);
            return 0;
        }else{
            int maxi=*st.begin();
            int idx=0;
            auto it1=st.begin();
            auto it2=st.begin();
            ++it2;
            for(;it2!=st.end();++it2,++it1){
                int d=(*it2-*it1)/2;
                if(d>maxi){
                    maxi=d;
                    idx=*it1+d;
                }
            }
            if(size-*it1>maxi) idx=size;
            st.insert(idx);
            return idx;
        }
    }
    
    void leave(int p) {
        st.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */