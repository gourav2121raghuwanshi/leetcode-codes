class MedianFinder {
public:
    // multiset<int>left;
    // multiset<int>right;
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<>>right;
    MedianFinder() {
    }
    
    void addNum(int num) {
        // left.insert(num);
        left.push(num);
        // auto it=left.end();
        // --it;
        // right.insert(*it);
        // left.erase(it);
        right.push(left.top());
        left.pop();
        if(right.size()-left.size()>1){
            // left.insert(*right.begin());
            // right.erase(right.begin());
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(right.empty()) return -1.0;
        if(left.size()==right.size()){
            return (right.top()+ left.top() )*1.0/2;
        }else {
            return right.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */