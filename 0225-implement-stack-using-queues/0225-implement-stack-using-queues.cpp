class MyStack {
     queue<int> a;
    queue<int> b;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        while(!a.empty()){
            b.push(a.front()); a.pop();
        }
        a.push(x);
        while(!b.empty()){
            a.push(b.front());
            b.pop();
        }
    }
    
    int pop() {
       int v= a.front();
        a.pop();
        return v;
    }
    
    int top() {
         int v= a.front();
        return v;
    }
    
    bool empty() {
        return a.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */