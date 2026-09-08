// Last updated: 9/9/2026, 12:14:32 AM
1class Solution {
2public:
3    int firstUniqChar(string s) {
4        unordered_map<int, int> mpp;
5        for (auto it : s) {
6            mpp[it]++;
7        }
8        for (int i = 0; i < s.size(); i++) {
9            if (mpp[s[i]] == 1) {
10                return i;
11            }
12        }
13
14        return -1;
15    }
16};