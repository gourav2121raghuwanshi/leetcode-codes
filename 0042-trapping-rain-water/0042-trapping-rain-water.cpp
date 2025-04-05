class Solution {
public:
    int trap(vector<int>& height) {
       int ans=0;
       int n=height.size();
       vector<int>prevL(n);
       vector<int>nextL(n);
       int m1=0;
       int m2=0;
       for(int i=0;i<n;++i){
        m1=max(m1,height[i]);
        m2=max(m2,height[n-i-1]);
        prevL[i]=m1;
        nextL[n-i-1]=m2;
       }
       prevL[0]=nextL[n-1]=-1;

       for(int i=0;i<n;++i)
       {
        int value=min(prevL[i],nextL[i])-height[i];
        if(value>0) ans+=value;
       }
       return ans;
    }
};