// Last updated: 7/18/2026, 2:04:24 PM
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> result;
        for (const string& word : words) {
            if (canForm(word, dict)) {
                result.push_back(word);
            }
        }
        return result;
    }

private:
    bool canForm(const string& word, unordered_set<string>& dict) {
        int n = word.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = (i == n ? 1 : 0); j < i; ++j) {
                if (dp[j] && dict.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};