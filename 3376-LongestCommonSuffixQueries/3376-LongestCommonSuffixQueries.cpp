// Last updated: 7/18/2026, 1:59:47 PM
class Solution {
    struct TrieNode {
        int child[26];
        int idx;

        TrieNode() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

public:
    vector<TrieNode> trie;

    bool better(int currIdx, int storedIdx,
                vector<string>& wordsContainer) {
        if (storedIdx == -1) return true;

        int currLen = wordsContainer[currIdx].size();
        int storedLen = wordsContainer[storedIdx].size();

        if (currLen < storedLen) return true;

        return currLen == storedLen &&
               currIdx < storedIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(TrieNode());

        for (int i = 0; i < wordsContainer.size(); i++) {
            string word = wordsContainer[i];
            reverse(word.begin(), word.end());

            int node = 0;

            if (better(i, trie[node].idx, wordsContainer))
                trie[node].idx = i;

            for (char ch : word) {
                int c = ch - 'a';

                if (trie[node].child[c] == -1) {
                    trie[node].child[c] = trie.size();
                    trie.push_back(TrieNode());
                }

                node = trie[node].child[c];

                if (better(i, trie[node].idx, wordsContainer))
                    trie[node].idx = i;
            }
        }

        vector<int> ans;

        for (string query : wordsQuery) {
            reverse(query.begin(), query.end());

            int node = 0;

            for (char ch : query) {
                int c = ch - 'a';

                if (trie[node].child[c] == -1)
                    break;

                node = trie[node].child[c];
            }

            ans.push_back(trie[node].idx);
        }

        return ans;
    }
};