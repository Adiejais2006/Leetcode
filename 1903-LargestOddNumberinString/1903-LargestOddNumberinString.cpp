// Last updated: 9/9/2026, 12:51:58 PM
1class Solution {
2public:
3    string largestOddNumber(string num) {
4        for (int i = num.length() - 1; i >= 0; --i) {
5            if ((num[i] - '0') % 2 != 0) {
6                return num.substr(0, i + 1);
7            }
8        }
9        return "";
10    }
11};
12