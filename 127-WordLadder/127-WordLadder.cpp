// Last updated: 7/18/2026, 2:06:14 PM
class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
         queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            string word = it.first;
            int steps = it.second;

            if (word == targetWord) return steps;
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    // exits
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};