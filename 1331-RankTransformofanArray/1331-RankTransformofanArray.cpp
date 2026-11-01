// Last updated: 11/1/2026, 8:49:29 PM
1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        int n = arr.size();
5        vector<int> temp = arr;
6        sort(temp.begin(), temp.end());
7        unordered_map<int, int> mpp;
8        int r = 1;
9        for (auto it : temp) {
10            if (mpp.find(it) == mpp.end())
11                mpp[it] = r++;
12        }
13        for (int i = 0; i < n; i++) {
14            arr[i] = mpp[arr[i]];
15        }
16        return arr;
17    }
18};