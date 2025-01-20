class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        for(int i=0;i<mat.size();++i){
            for(int j=0;j<mat[0].size();++j){
                row[mat[i][j]]=i;
                col[mat[i][j]]=j;
            }
        }
        unordered_map<int,int>rowCnt;
        unordered_map<int,int>colCnt;
        for(int j=0;j<arr.size();++j){
            int ele=arr[j];
            int r=row[ele];
            int c=col[ele];
            ++rowCnt[r];
            ++colCnt[c];
            if(rowCnt[r]==mat[0].size()) return j;
            if(colCnt[c]==mat.size()) return j;
        }
        return -1;
    }
};