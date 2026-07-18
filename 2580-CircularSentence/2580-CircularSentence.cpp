// Last updated: 7/18/2026, 2:00:31 PM
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        int cnt = 0;
        bool yes = true;
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                cnt++;
                if (sentence[i - 1] != sentence[i + 1]) {
                    yes = false;
                }
            }
        }
        if (cnt == 0) {
            return (sentence[0] == sentence[n - 1]);
        }
        if (yes && sentence[0] == sentence[n - 1])

            return true;
        return false;
    }
};