class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
     int fc=0;
     int tc=0;
     for(auto&i:bills){
        if(i==5){
            ++fc;
        }else if(i==10){
            if(fc) --fc;
            else return false;
            ++tc;
        }else if(i==20){
            if(fc && tc){
                --fc;
                --tc;
            }else if(fc>=3){
                fc-=3;
            }
            else return false;
        }
     }
     return true;
    }
};