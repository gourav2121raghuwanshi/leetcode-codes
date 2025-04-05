class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return 1;
        }else{
            int c=1;
            while(!st.empty() && price>=st.top().first){
                c+=st.top().second;
                st.pop();
            }
            st.push({price,c});
            return c;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */