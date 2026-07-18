// Last updated: 7/18/2026, 2:05:36 PM

struct node {
    node* links[26];
    bool flag = false;

    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, node* newNode) { links[ch - 'a'] = newNode; }
    node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Trie {
private:
    node* root;

public:
    Trie() { root = new node(); }

    void insert(string word) {
        node* nodePtr = root;
        for (char ch : word) {
            if (!nodePtr->containsKey(ch)) {
                nodePtr->put(ch, new node());
            }
            nodePtr = nodePtr->get(ch);
        }
        nodePtr->setEnd();
    }

    bool search(string word) {
        node* nodePtr = root;
        for (char ch : word) {
            if (!nodePtr->containsKey(ch)) {
                return false;
            }
            nodePtr = nodePtr->get(ch);
        }
        return nodePtr->isEnd();
    }

    bool startsWith(string prefix) {
        node* nodePtr = root;
        for (char ch : prefix) {
            if (!nodePtr->containsKey(ch)) {
                return false;
            }
            nodePtr = nodePtr->get(ch);
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