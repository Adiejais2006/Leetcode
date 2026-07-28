// Last updated: 7/28/2026, 7:38:57 PM
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        int n = s.size();
5        vector<int> freq(26, 0);
6        for (char c : s)
7            freq[c - 'a']++;
8        string ans(n, ' ');
9        int left = 0, right = n - 1;
10        for (int i = 0; i < 26; i++) {
11            while (freq[i] >= 2) {
12                ans[left++] = char(i + 'a');
13                ans[right--] = char(i + 'a');
14                freq[i] -= 2;
15            }
16            if (freq[i] == 1) {
17                ans[n / 2] = char(i + 'a');
18            }
19        }
20        return ans;
21    }
22};