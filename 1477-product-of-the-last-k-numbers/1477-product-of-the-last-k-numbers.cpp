class ProductOfNumbers {
public:
    vector<int> v;
    int zc=0;
    int prod=1;
    ProductOfNumbers() {}

    void add(int num) {
        if(num==0){
            v.clear();
        }
        v.push_back(num);
        
    }

    int getProduct(int k) {
        int prod=1;
        int j=v.size()-1;
        while(j>=0 && k--){
            prod*=v[j--];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */