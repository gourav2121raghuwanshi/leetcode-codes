class node {
public:
    node* links[26];
    bool end = false;
    string word;
    node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }
};

class Solution {
    int n, m, maxLen;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> ans;

    void insert(string& word, node* curr) {
        for (auto& j : word) {
            if (curr->links[j - 'a'] == nullptr) {
                curr->links[j - 'a'] = new node();
            }
            curr = curr->links[j - 'a'];
        }
        curr->end = true;
        curr->word = word;
    }

    void find(int i, int j, vector<vector<char>>& board, node* curr) {
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '#' ||
            curr == nullptr || curr->links[board[i][j] - 'a'] == nullptr)
            return;

        char val = board[i][j];
        curr = curr->links[val - 'a'];

        if (curr->end == true) {
            ans.push_back(curr->word);
            curr->end = false; // remove end as we got that word, and all words
                               // are unique
        }

        board[i][j] = '#';
        for (auto& k : dir) {
            int dr = k.first + i;
            int dc = k.second + j;
            find(dr, dc, board, curr);
        }
        board[i][j] = val;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        n = board.size();
        m = board[0].size();

        node* root = new node();

        for (auto& word : words) {
            insert(word, root);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                node* curr = root;
                if (curr->links[board[i][j] - 'a'] != nullptr) {
                    find(i, j, board, curr);
                }
            }
        }

        return ans;
    }
};
