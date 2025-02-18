class Solution {
    bool valid(double mid,vector<vector<int>>& squares){
        double a=0;
        double b=0;

        for(auto&i:squares){
            if(i[1]+i[2]<mid){
                a+=i[2]*1.0*i[2];
            }else if(mid<i[1]){
                b+=i[2]*1.0*i[2];
            }else{
                a+=(mid-i[1])*1LL*i[2];
                b+=i[2]*1.0*(i[1]+i[2]-mid);
            }
        }
        return a>=b;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l=0;
        double h=1e15;
       while(h-l>1e-5){
            double mid=l+(h-l)/2;
            if(valid(mid,squares)){
                h=mid;
            }else{
                l=mid;
            }
        }
        return l;
    }
};