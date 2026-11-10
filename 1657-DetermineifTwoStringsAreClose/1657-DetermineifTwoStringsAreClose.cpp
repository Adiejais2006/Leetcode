// Last updated: 11/10/2026, 11:20:39 PM
1class Solution {
2public:
3    bool closeStrings(std::string word1, std::string word2) {
4        vector<int> freq1(26, 0);
5        vector<int> freq2(26, 0);
6        for (char ch : word1) {
7            freq1[ch - 'a']++;
8        }
9        for (char ch : word2) {
10            freq2[ch - 'a']++;
11        }
12        for (int i = 0; i < 26; i++) {
13            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
14                return false;
15            }
16        }
17        sort(freq1.begin(), freq1.end());
18        sort(freq2.begin(), freq2.end());
19        for (int i = 0; i < 26; i++) {
20            if (freq1[i] != freq2[i]) {
21                return false;
22            }
23        }
24        return true;
25    }
26};
27
28
29