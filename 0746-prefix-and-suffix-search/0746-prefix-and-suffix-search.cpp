class node {
public:
    node* link[26];
    unordered_set<int> index;

    node() {
        for (int i = 0; i < 26; ++i)
            link[i] = nullptr;
    }
};

class Trie {
    node* prefroot = new node();
    node* suffroot = new node();

public:
    void insertPref(const string& s, int idx) {
        node* curr = prefroot;
        for (char i : s) {
            if (!curr->link[i - 'a']) {
                curr->link[i - 'a'] = new node();
            }
            curr = curr->link[i - 'a'];
            curr->index.insert(idx);
        }
    }

    unordered_set<int> getIndexListPref(const string& s) {
        node* curr = prefroot;
        for (char i : s) {
            if (!curr->link[i - 'a']) {
                return {};
            }
            curr = curr->link[i - 'a'];
        }
        return curr->index;
    }

    void insertSuff(const string& s, int idx) {
        node* curr = suffroot;
        for (char i : s) {
            if (!curr->link[i - 'a']) {
                curr->link[i - 'a'] = new node();
            }
            curr = curr->link[i - 'a'];
            curr->index.insert(idx);
        }
    }

    unordered_set<int> getIndexListSuff(const string& s) {
        node* curr = suffroot;
        for (char i : s) {
            if (!curr->link[i - 'a']) {
                return {};
            }
            curr = curr->link[i - 'a'];
        }
        return curr->index;
    }
};

class WordFilter {
    Trie trie;

public:
    WordFilter(vector<string>& words) {
        // to remove duplicate words;
        unordered_map<string, int> lastOccurrence;
        for (int i = 0; i < words.size(); ++i) {
            lastOccurrence[words[i]] = i;
        }

        for (auto& [word, index] : lastOccurrence) {
            trie.insertPref(word, index);
            string b = word;
            reverse(b.begin(), b.end());
            trie.insertSuff(b, index);
        }
    }

    int f(string pref, string suff) {
        unordered_set<int> a = trie.getIndexListPref(pref);
        if (a.empty())
            return -1;

        reverse(suff.begin(), suff.end());
        unordered_set<int> b = trie.getIndexListSuff(suff);

        if (b.empty())
            return -1;
        int ans = -1;

        for (int num : b) {
            if (a.count(num))
                ans = max(ans, num);
        }

        return ans;
    }
};
