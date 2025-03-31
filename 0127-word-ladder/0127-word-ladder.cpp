class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord))
            return 0;
        int ans = 1;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> vis;
        vis.insert(beginWord);
        bool f = true;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto front = q.front();
                string temp = front;
                q.pop();
                for (auto& i : temp) {
                    char org = i;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch != i) {
                            i = ch;
                            if (!vis.count(temp) && st.count(temp)) {
                                if(temp==endWord) return ans+1;
                                vis.insert(temp);
                                q.push(temp);
                            }
                            i = org;
                        }
                    }
                }
            }
            ++ans;
        }

        return 0;
    }
};