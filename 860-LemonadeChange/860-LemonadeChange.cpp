// Last updated: 11/1/2026, 3:24:54 PM
1class Solution {
2public:
3    bool lemonadeChange(vector<int>& bills) {
4        int five = 0;
5        int ten = 0;
6        for (auto it : bills) {
7            if (it == 5) {
8                five++;
9            } else if (it == 10) { // 5 dena hai
10                if (five >= 1) {
11                    five--;
12                    ten++;
13                } else
14                    return false;
15            } else {
16                // 15 dena hai
17                // 10 + 5
18                // 5+ 5 + 5
19                if (ten >= 1 && five >= 1) {
20                    ten--;
21                    five--;
22                } else if (ten == 0 && five >= 3) {
23                    five -= 3;
24                } else
25                    return false;
26            }
27        }
28        return true;
29    }
30};