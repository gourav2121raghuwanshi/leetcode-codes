class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int count = 0;
        map<int, int> mp;
        for(auto&i:queries){
            mp[i]=1;
        }
        vector<pair<int,int>>dir={
{0,1},{0,-1},{1,0},{-1,0}
        };
        vector<vector<int>>vis(n,vector<int>(m,false));
        vis[0][0]=true;
        for(auto&i:mp){
            int val=i.first;
            if(pq.empty() || pq.top()[0]>=val){
                mp[val]=count;
                continue;
            }
            while(!pq.empty()){
                auto top=pq.top();
                if(top[0]>=val)break;
                pq.pop();
                ++count;
                for(auto&i:dir){
                    int dx=i.first+top[1];
                    int dy=i.second+top[2];
                    if(dx>=0 && dx<n && dy>=0 && dy<m && !vis[dx][dy]){
                        vis[dx][dy]=true;
                        pq.push({grid[dx][dy],dx,dy});
                    }
                }
            }
            mp[val]=count;
        }
        vector<int>ans;
        for(auto&i:queries){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};