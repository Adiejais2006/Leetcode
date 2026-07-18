// Last updated: 7/18/2026, 2:06:15 PM
class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();

            unordered_set<string> levelVisited;

            while (sz--) {
                string word = q.front();
                q.pop();

                string original = word;

                for (int i = 0; i < word.size(); i++) {
                    char orig = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        if (st.count(word) && !visited.count(word)) {

                            if (!levelVisited.count(word)) {
                                q.push(word);
                                levelVisited.insert(word);
                            }

                            parent[word].push_back(original);

                            if (word == endWord)
                                found = true;
                        }
                    }

                    word[i] = orig;
                }
            }

            for (auto x : levelVisited)
                visited.insert(x);
        }

        if (!found) return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};