class node {
public:
    node* link[26];
    vector<int> index;

    node() {
        for (int i = 0; i < 26; ++i)
            link[i] = nullptr;
    }

    ~node() { // Destructor to prevent memory leaks
        for (int i = 0; i < 26; ++i) {
            delete link[i];
        }
    }
};

class Trie {
    node* prefroot = new node();
    node* suffroot = new node();

public:
    ~Trie() { // Ensure allocated memory is freed
        delete prefroot;
        delete suffroot;
    }

    void insertPref(const string& s, int idx) {
        node* curr = prefroot;
        for (char i : s) {
            if (!curr->link[i - 'a']) {
                curr->link[i - 'a'] = new node();
            }
            curr = curr->link[i - 'a'];
            curr->index.push_back(idx);
        }
    }

    vector<int> getIndexListPref(const string& s) {
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
            curr->index.push_back(idx);
        }
    }

    vector<int> getIndexListSuff(const string& s) {
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
        vector<int> a = trie.getIndexListPref(pref);
        if (a.empty())
            return -1;

        reverse(suff.begin(), suff.end());
        vector<int> b = trie.getIndexListSuff(suff);

        if (b.empty())
            return -1;
        int ans = -1;
        reverse(b.begin(), b.end());
        unordered_set<int> elements(a.begin(), a.end());
        for (int& num : b) {
            if (elements.count(num))
            ans = max(ans, num);
        }

        return ans;
    }
};
