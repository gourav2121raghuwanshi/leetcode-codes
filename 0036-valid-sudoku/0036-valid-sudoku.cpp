class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;++i){
            unordered_map<char,bool>mp;
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                    if(mp.count(board[i][j])) return false;
                    mp[board[i][j]]=true;
                }
            }
        }
           for(int i=0;i<m;++i){
            unordered_map<char,bool>mp;
            for(int j=0;j<n;j++){
                if(board[j][i]!='.'){
                    if(mp.count(board[j][i])) return false;
                    mp[board[j][i]]=true;
                }
            }
        }
        for(int i=0;i<n;i+=3){
            for(int j=0;j<m;j+=3){
                   unordered_map<char,bool>mp;
                for(int k1=i;k1<i+3;k1++){
                    for(int k2=j;k2<j+3;++k2){
                        if(board[k1][k2]!='.'){
                    if(mp.count(board[k1][k2])) return false;
                    mp[board[k1][k2]]=true;
                }
                    }
                }
            }
        }
        return true;
    }
};