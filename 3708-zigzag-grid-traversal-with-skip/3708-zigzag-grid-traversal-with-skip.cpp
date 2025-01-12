class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int>ans;
        int n=grid.size();
        int m=grid[0].size();
        int i=0;
        int j=0;
        bool dir=1;
        while(i<n && j<m && i>=0 && j>=0){
            ans.push_back(grid[i][j]);
            if(dir)
            j+=2;
            else j-=2;
            if(j>=m){
                if(j==m)
                j=m-1;
                else j=m-2;
                i++;
                dir=1-dir;
            }else if(j<0){
                dir=1-dir;
                if(j==-1) j=0;
                else j=1;
                ++i;
            }
        }

        return ans;
    }
};