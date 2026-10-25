// Last updated: 10/25/2026, 11:24:10 PM
1class Solution {
2public:
3    int countStaircase(vector<int>& nums) {
4        int n = nums.size();
5        int cnt = 0;
6        for (int i = 0; i < n; i++) {
7            unordered_map<int, int> mpp;
8            vector<int> temp;
9            for (int j = i; j < n; j++) {
10                if (mpp[nums[j]] == 0)
11                    temp.push_back(nums[j]);
12                mpp[nums[j]]++;
13                int k = 1;
14                bool done = true;
15                for (auto it : temp) {
16                    if (mpp[it] == k)
17                        k++;
18                    else {
19                        done = false;
20                        break;
21                    }
22                }
23                if (done)
24                    cnt++;
25            }
26        }
27        return cnt;
28    }
29};