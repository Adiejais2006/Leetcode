// Last updated: 7/29/2026, 8:08:12 PM
1class Solution {
2public:
3    vector<string> fizzBuzz(int n) {
4        vector<string> ans;
5
6        for (int i = 1; i <= n; i++) {
7            if (i % 3 == 0 && i % 5 == 0)
8                ans.push_back("FizzBuzz");
9            else if (i % 3 == 0)
10                ans.push_back("Fizz");
11            else if (i % 5 == 0)
12                ans.push_back("Buzz");
13            else
14                ans.push_back(to_string(i));
15        }
16        return ans;
17    }
18};