class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setbitc=0;
        while(num2){
            ++setbitc;
            num2= (num2)&(num2-1);
        }
        int ans=0;
        vector<int>v(32,0);
        vector<int>one(32,0);
        for(int i=31;i>=0;--i){
            if(num1&(1<<i)){
                if(setbitc) {
                    ans=ans|(1<<i);
                    --setbitc;
                    one[i]=1;
                }else one[i]=2;
            }
        }
        for(int i=0;i<31 && setbitc>0 ;i++){
            if(!one[i]){
                ans=(ans|(1<<i));
                --setbitc;
            }
        }
        return ans;
    }
};