class node {
public:
    int c = 0;
    node* link[26];
    node() {
        for (int i = 0; i < 26; ++i) {
            link[i] = nullptr;
        }
    }
};

class Solution {
    node* root = new node();

     void ins(const string& s) {
        node* curr = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!curr->link[idx])
                curr->link[idx] = new node();
            curr = curr->link[idx];
            curr->c++;
        }
    }

    void rmv(const string& s) {
        node* curr = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!curr->link[idx])
                return; 
            curr = curr->link[idx];
            curr->c--;
        }
    }

     int getMax(int k, node* curr) {
        if (!curr)
            return 0;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (curr->link[i] && curr->link[i]->c >= k) {
                ans = max(ans, 1 + getMax(k, curr->link[i]));
            }
        }
        return ans;
    }

     string getLongestPrefixString(int k, node* curr) {
        string best = "";
        for (int i = 0; i < 26; ++i) {
            if (curr->link[i] && curr->link[i]->c >= k) {
                string candidate = string(1, 'a' + i) +
                                   getLongestPrefixString(k, curr->link[i]);
                if (candidate.size() > best.size()) {
                    best = candidate;
                }
            }
        }
        return best;
    }

public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        for (auto& s : words) {
            ins(s);
        }

        string initialPrefix = getLongestPrefixString(k, root);
        // cout<<initialPrefix;
        int maxi = initialPrefix.size();
        rmv(initialPrefix);
        int smaxi=getMax(k,root);
        vector<int> ans;
        unordered_map<string, int> mp;
        for (auto& s : words) {
            if (mp.count(s)) {
                ans.push_back(mp[s]);
            } else {
                int len=min((int)s.size(),maxi);
                if(s.substr(0,len)!=initialPrefix){
                    ans.push_back(maxi);
                    mp[s]=maxi;
                }else{
                    ans.push_back(smaxi);
                }
            }
        }
        return ans;
    }
};
