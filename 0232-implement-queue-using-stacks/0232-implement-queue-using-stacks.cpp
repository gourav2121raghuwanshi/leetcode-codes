class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int>a;
        while(!st.empty()){
            a.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!a.empty()){
            st.push(a.top());
            a.pop();
        }
    }
    
    int pop() {
        int v=st.top(); st.pop();
        return v;
    }
    
    int peek() {
        int v=st.top();
        return v;
    }
    
    bool empty() {
        return st.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */