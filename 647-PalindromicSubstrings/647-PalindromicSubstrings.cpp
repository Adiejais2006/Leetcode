// Last updated: 10/22/2026, 2:08:55 PM
1class Solution {
2public:
3    int countSubstrings(string s) {
4        int n = s.length();
5        int count = 0;
6        for (int i = 0; i < n; ++i) {
7            count += expandAroundCenter(s, i, i);
8            count += expandAroundCenter(s, i, i + 1);
9        }
10        return count;
11    }
12
13private:
14    int expandAroundCenter(const string& s, int left, int right) {
15        int count = 0;
16        while (left >= 0 && right < s.length() && s[left] == s[right]) {
17            count++;
18            left--;
19            right++;
20        }
21        return count;
22    }
23};