// Last updated: 11/18/2026, 3:21:40 PM
1class Solution {
2public:
3    int minChanges(string s) {
4        char currentChar = s[0];
5        int consecutiveCount = 0;
6        int minChangesRequired = 0;
7        for (int i = 0; i < s.length(); i++) {
8            if (s[i] == currentChar) {
9                consecutiveCount++;
10                continue;
11            }
12            if (consecutiveCount % 2 == 0) {
13                consecutiveCount = 1;
14            }
15            else {
16                consecutiveCount = 0;
17                minChangesRequired++;
18            }
19            currentChar = s[i];
20        }
21        return minChangesRequired;
22    }
23};