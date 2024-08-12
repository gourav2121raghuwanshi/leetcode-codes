class MyQueue {
    stack<int>a,b;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        a.push(x);
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
    }
    
    int pop() {
        if(a.empty()) return -1;
        int v=a.top();
        a.pop();
        return v;
    }
    
    int peek() {
        if(a.empty()) return -1;
        int v=a.top();
        return v;
    }
    
    bool empty() {
        return a.size()==0;
    }
};