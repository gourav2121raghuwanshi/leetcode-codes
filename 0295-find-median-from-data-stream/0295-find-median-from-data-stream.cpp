class MedianFinder {
public:
    multiset<int>left;
    multiset<int>right;
    MedianFinder() {
    }
    
    void addNum(int num) {
        left.insert(num);
        auto it=left.end();
        --it;
        right.insert(*it);
        left.erase(it);
        if(right.size()-left.size()>1){
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    
    double findMedian() {
        if(right.empty()) return -1.0;
        if(left.size()==right.size()){
            double val1=*right.begin();
            auto it=left.end();
            --it;
            return (val1+ (*it))*1.0/2;
        }else {
            return *right.begin();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */