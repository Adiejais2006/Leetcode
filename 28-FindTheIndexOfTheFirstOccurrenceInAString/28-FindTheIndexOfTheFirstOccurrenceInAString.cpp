// Last updated: 7/18/2026, 2:07:40 PM
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (n == 0) return 0;
        
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && needle[i] != needle[j]) {
                j = lps[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        int i = 0, j = 0;
        while (i < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == n) {
                return i - n;
            } else if (i < m && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};