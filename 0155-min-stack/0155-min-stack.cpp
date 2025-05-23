class MinStack {
    stack<pair<int,int>>st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else st.push({min(val,st.top().first),val});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().second;
    }
    
    int getMin() {
        return st.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */