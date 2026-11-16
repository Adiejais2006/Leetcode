// Last updated: 11/16/2026, 4:41:14 PM
1class Solution {
2public:
3    string digitSum(string s, int k) {
4        while (s.size() > k) {
5            string temp = "";
6            int cnt = 0;
7            int sum = 0;
8            for (auto it : s) {
9                sum += it - '0';
10                cnt++;
11                if (cnt == k) {
12                    temp += to_string(sum);
13                    cnt = 0;
14                    sum = 0;
15                }
16            }
17            if (cnt > 0) {
18                temp += to_string(sum);
19            }
20            s = temp;
21        }
22
23        return s;
24    }
25};