class MyStack {
    queue<int>a;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int>b;
        if(a.empty()){
            a.push(x);
        }else{
            while(!a.empty()){
                b.push(a.front());
                a.pop();
            }
            a.push(x);
            while(!b.empty()){
                a.push(b.front());
                b.pop();
            }
        }

    }
    
    int pop() {
        if(a.empty()) return -1;
        int val=a.front();
        a.pop();
        return val;
    }
    
    int top() {
        if(a.empty()) return -1;
        return a.front();
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