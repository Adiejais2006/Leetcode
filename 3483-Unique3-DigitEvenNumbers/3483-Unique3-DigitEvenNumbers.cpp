// Last updated: 9/11/2026, 12:37:06 PM
1class Solution {
2public:
3    int totalNumbers(vector<int>& digits) {
4        unordered_set<int> seen;
5        int n = digits.size();
6        for(int h = 0; h < n; h++){
7            if (digits[h] == 0) continue;
8            for(int t = 0; t < n; t++){
9                if (t == h) continue;
10                for(int u = 0; u < n; u++){
11                    if(u == h || u == t) continue;
12                    if(digits[u] % 2 != 0) continue;
13
14                    int num = digits[h]*100+digits[t]*10+digits[u];
15                    seen.insert(num);
16                }
17            }
18        }
19
20        return seen.size();
21    }
22};