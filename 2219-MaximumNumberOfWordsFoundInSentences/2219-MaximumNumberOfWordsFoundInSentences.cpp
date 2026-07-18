// Last updated: 7/18/2026, 2:01:01 PM
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        int n = sentences.size();
        for (int i = 0; i < n; i++) {
            string words = sentences[i];
            int m = words.size();
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (isalpha(words[i])) {
                    cnt++;
                    while (i < m && isalpha(words[i]))
                        i++;
                }
            }

            ans = max(ans, cnt);
        }
        return ans;
    }
};