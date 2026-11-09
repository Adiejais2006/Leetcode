// Last updated: 11/9/2026, 3:18:02 PM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        int n = strs.size();
5        vector<vector<string>> ans;
6        unordered_map<string, vector<string>> mpp;
7        for (auto it : strs) {
8            string temp=it;
9            sort(temp.begin(),temp.end());
10            mpp[temp].push_back(it);
11        }
12
13        for (auto it : mpp) {
14            ans.push_back(it.second);
15        }
16        return ans;
17    }
18};