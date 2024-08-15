class Trie
{
    class node
    {
    public:
        node *link[26];
        bool end;
        node()
        {
            end = false;
            for (int i = 0; i < 26; ++i)
            {
                link[i] = NULL;
            }
        }
    };

    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(string word)
    {
        node *curr = root;
        for (auto &i : word)
        {
            if (curr->link[i - 'a'] == nullptr)
            {
                curr->link[i - 'a'] = new node();
            }
            curr = curr->link[i - 'a'];
        }
        curr->end = true;
    }

    bool search(string word)
    {
        node *curr = root;
        for (auto &i : word)
        {
            if (curr->link[i - 'a'] == nullptr)
            {
                return false;
            }
            curr = curr->link[i - 'a'];
        }
        return curr->end == true;
    }

    bool startsWith(string prefix)
    {
        node *curr = root;
        for (auto &i : prefix)
        {
            if (curr->link[i - 'a'] == nullptr)
            {
                return false;
            }
            curr = curr->link[i - 'a'];
        }
        return true;
    }
};