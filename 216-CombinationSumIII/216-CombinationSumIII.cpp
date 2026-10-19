// Last updated: 10/19/2026, 4:51:32 PM
1class Solution {
2    void func(int ind, vector<vector<int>>& ans, vector<int>& temp, int k,
3             int n) {
4
5        if (n == 0 && temp.size() == k) {
6            ans.push_back(temp);
7            return;
8        }
9        if (n < 0 || ind > 9 || temp.size() > k)
10            return;
11        func(ind + 1, ans, temp, k, n);
12        temp.push_back(ind);
13        func(ind + 1, ans, temp, k, n - ind);
14        temp.pop_back();
15    }
16
17public:
18    vector<vector<int>> combinationSum3(int k, int n) {
19        vector<vector<int>> ans;
20        vector<int> temp;
21        func(1, ans, temp, k, n);
22        return ans;
23    }
24};