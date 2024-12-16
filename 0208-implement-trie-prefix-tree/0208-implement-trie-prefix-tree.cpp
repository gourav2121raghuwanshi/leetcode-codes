class Trie {
    class node {
    public:
        node* link[26];
        bool end = false;
        node() {
            for (int i = 0; i < 26; ++i)
                link[i] = nullptr;
        }
    };

public:
    Trie() {}
    node* root = new node();

    void insert(string word) {
        node* curr = root;
        for (auto& i : word) {
            if (curr->link[i - 'a'] == nullptr) {
                curr->link[i - 'a'] = new node();
            }
            curr = curr->link[i - 'a'];
        }
        curr->end = true;
    }

    bool search(string word) {
        node* curr = root;
        for (auto& i : word) {
            if (curr->link[i - 'a'] == nullptr) {
                return false;
            }
            curr = curr->link[i - 'a'];
        }
        return curr->end == true;
    }

    bool startsWith(string word) {
        node* curr = root;
        for (auto& i : word) {
            if (curr->link[i - 'a'] == nullptr) {
                return false;
            }
            curr = curr->link[i - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */