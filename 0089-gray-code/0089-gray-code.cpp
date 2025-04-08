class Solution {
    /*
    0<-i   i/2->0 xor -> 0
1<-i   i/2->0 xor -> 1
2<-i   i/2->1 xor -> 3
3<-i   i/2->1 xor -> 2
4<-i   i/2->2 xor -> 6
5<-i   i/2->2 xor -> 7
6<-i   i/2->3 xor -> 5
7<-i   i/2->3 xor -> 4*/
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        int powerOf2= (1<<n);
        for(int i=0;i<powerOf2;++i){
            int xorOfI_withiby2 = i^(i/2);
            ans.push_back(xorOfI_withiby2);
        }
        return ans;
    }
};