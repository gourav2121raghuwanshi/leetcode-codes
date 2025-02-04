class Solution {
    // apply topoSort on groups also
    // for all those with -1 group assign unique groups to each of them
    // now apply topo Sort twice
    // first to find group Order
    // them to find itemOrder
    // the in group Ordering -> place the items which are now in Order
    // to refer : https://www.youtube.com/watch?v=Uu03ktYBWMY
public:
    vector<int> sortItems(int n, int m, vector<int>& group,
                          vector<vector<int>>& beforeItems) {
        vector<int> in(n, 0);

        unordered_map<int, int> groupOfEle;
        unordered_map<int, vector<int>> itemAdj;
        int c = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                groupOfEle[i] = c++;
            } else {
                groupOfEle[i] = group[i];
            }
        }
        unordered_map<int, vector<int>> groupAdj;
        vector<int> groupIn(c, 0);
        cout << " no of grps : " << c << endl;
        for (int i = 0; i < n; ++i) {
            if (beforeItems[i].empty())
                continue;
            else {
                in[i] += beforeItems[i].size();
                for (auto& j : beforeItems[i]) {
                    if (groupOfEle[j] != groupOfEle[i]) {
                        groupAdj[groupOfEle[j]].push_back(groupOfEle[i]);
                        ++groupIn[groupOfEle[i]];
                    }
                    itemAdj[j].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < c; i++) {
            if (groupIn[i] == 0) {
                q.push(i);
            }
        }
        vector<int> groupOrder;
        while (!q.empty()) {
            auto front = q.front();
            groupOrder.push_back(front);
            q.pop();
            for (auto& kk : groupAdj[front]) {
                --groupIn[kk];
                if (groupIn[kk] == 0)
                    q.push(kk);
            }
        }

        vector<int> zz;
        if (groupOrder.size() != c)
            return zz;

        vector<int> itemOrder;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            itemOrder.push_back(front);
            for (auto& j : itemAdj[front]) {
                --in[j];
                if (in[j] == 0)
                    q.push(j);
            }
        }
         if (itemOrder.size() != n)
            return zz;

        unordered_map<int, vector<int>> groupKeItemsKaOrder;
        for (int i = 0; i < n; i++) {
            int group=groupOfEle[itemOrder[i]];
            groupKeItemsKaOrder[group].push_back(itemOrder[i]);
        }
        
        for (auto& i : groupOrder) {
            ans.insert(ans.end(), groupKeItemsKaOrder[i].begin(),
                       groupKeItemsKaOrder[i].end());
        }
       

        return ans.size() == n ? ans : zz;
    }
};