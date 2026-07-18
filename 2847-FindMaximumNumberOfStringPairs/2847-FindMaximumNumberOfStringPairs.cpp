// Last updated: 7/18/2026, 2:00:04 PM
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string temp = words[j];
                reverse(temp.begin(), temp.end());
                if (words[i] == temp)
                    ans++;
            }
        }
        return ans;
    }
};