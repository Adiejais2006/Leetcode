// Last updated: 11/1/2026, 3:28:11 PM
1class Solution {
2public:
3    bool checkValidString(string s) {
4        int leftMin = 0, leftMax = 0;
5
6        for (char c : s) {
7            if (c == '(') {
8                leftMin++;
9                leftMax++;
10            } else if (c == ')') {
11                leftMin--;
12                leftMax--;
13            } else {
14                leftMin--;
15                leftMax++;
16            }
17            if (leftMax < 0) return false;
18            if (leftMin < 0) leftMin = 0;
19        }
20        
21        return leftMin == 0;
22    }
23};