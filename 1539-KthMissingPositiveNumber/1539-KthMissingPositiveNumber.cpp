// Last updated: 10/26/2026, 10:00:56 PM
1class Solution {
2public:
3    int findKthPositive(vector<int>& arr, int k) {
4        unordered_map<int, int> mpp;
5        for (auto it : arr)
6            mpp[it]++;
7
8        int cnt = 0;
9        int i = 1;
10        while (cnt != k) {
11            if (mpp.find(i) == mpp.end())
12                cnt++;
13            if (cnt == k)
14                return i;
15            i++;
16        }
17        return -1;
18    }
19};