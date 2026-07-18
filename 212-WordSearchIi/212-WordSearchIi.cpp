// Last updated: 7/18/2026, 2:05:33 PM
class Solution {
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            word = "";
        }
    };

    void insert(TrieNode* root, const string& w) {
        TrieNode* node = root;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = w;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& res) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];

        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word = ""; 
        }

        board[i][j] = '#';

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size()) {
                dfs(board, ni, nj, node, res);
            }
        }

        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (auto& w : words) insert(root, w);

        vector<string> res;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, res);
            }
        }

        return res;
    }
};