class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        vector<pair<int,int>>direction={{0,1},{1,0},{0,-1},{-1,0}};
        int ele=0;
        int i=rStart;
        int j=cStart;
        int dir=0;
        while(ans.size()<rows*cols){
            if(dir==0 || dir==2) ++ele;

            for(int col=0;col<ele;++col){
                if(i>=0 && j>=0 && i<rows && j<cols){
                    ans.push_back({i,j});
                }
                i+=direction[dir].first;
                j+=direction[dir].second;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};