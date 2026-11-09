// Last updated: 11/9/2026, 3:02:53 PM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        int n = strs.size();
5        vector<vector<string>> ans;
6        map<vector<int>, vector<string>> mpp;
7        for (auto it : strs) {
8            vector<int> a(26, 0);
9            for (auto i : it) {
10                a[i - 'a']++;
11            }
12            mpp[a].push_back(it);
13        }
14
15        for (auto it : mpp) {
16            ans.push_back(it.second);
17        }
18        return ans;
19    }
20};