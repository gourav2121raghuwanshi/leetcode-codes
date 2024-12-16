class WordDictionary {
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

    bool searchh(string word, node* curr) {
       
        if (word.empty() && curr->end)
            return 1;
        if (word.empty() )
            return false;

        for (int k = 0; k < word.size(); ++k) {
            char i = word[k];
            if (i == '.') {
                for (auto& j : curr->link) {
                    if (j != nullptr)
                        if (searchh(word.substr(k + 1), j))
                            return true;
                }
                return false;
            } else {
                if(!curr->link[i - 'a']) return false;

                if (searchh(word.substr(k+1), curr->link[i - 'a']))
                            return true;
                else return false;
            }
        }
return curr->end;
    }

public:
    WordDictionary() {}

    void addWord(string word) { insert(word); }

    bool search(string word) {
        node* curr = root;
        return searchh(word, curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */