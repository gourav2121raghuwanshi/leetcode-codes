class CustomStack {
public:
    int *arr;
    int idx=-1;
    int size;
    CustomStack(int maxSize) {
        arr=new int[maxSize];
        size=maxSize;
    }
    
    void push(int x) {
        if(idx+1<size){
            arr[++idx]=x;
        }
    }
    
    int pop() {
        if(idx==-1) return -1;
        int val=arr[idx];
        --idx;
        return val;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,idx+1);i++){
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */