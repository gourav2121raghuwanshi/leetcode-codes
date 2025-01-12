class Solution {
    unordered_map<int,vector<pair<int,int>>>radj;
    bool isNodeZeroReachable(int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto& [neighbor ,wt] : radj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) return false; 
    }
    return true; 
}
bool isValid(int n,int wt){
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()){
        auto front=q.front();
        q.pop();
        for (auto& [neighbor,weight] : radj[front]) {
            if (!visited[neighbor] && weight<=wt) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

 for (int i = 0; i < n; ++i) {
        if (!visited[i]) return false; 
    }
    return true; 
}

public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        for(auto&i:edges){
            radj[i[1]].push_back({i[0],i[2]});
        }
        if(!isNodeZeroReachable(n)) return -1;
        int mini=1;
        int maxi=1e6+1;
        int ans=-1;
        while(mini<=maxi){
            int mid=(mini+maxi)/2;
            if(isValid(n,mid)){
                ans=mid;
                maxi=mid-1;
            }else mini=mid+1;
        }
        return ans;
    }
};