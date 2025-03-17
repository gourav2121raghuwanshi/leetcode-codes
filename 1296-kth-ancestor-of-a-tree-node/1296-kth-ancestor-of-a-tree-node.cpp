class TreeAncestor {
    vector<vector<int>>up;
    int Log;
public:
    TreeAncestor(int n, vector<int>& parent) {
        Log=log2(n)+1;
        up.resize(n,vector<int>(Log,-1));
        // direct or 2^0 th parent of each node
        for(int i=0;i<n;i++){
            up[i][0]=parent[i];
        }

        // 2^j th parent of each node
        for(int j=1;j<Log;++j){
            for(int i=0;i<n;++i){
                if(up[i][j-1]!=-1){
                    up[i][j]=up[up[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=Log;i>=0;--i){
            if(k&(1<<i)){
                node=up[node][i];
                if(node==-1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */