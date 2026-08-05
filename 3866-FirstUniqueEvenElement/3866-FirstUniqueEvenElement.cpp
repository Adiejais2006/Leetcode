// Last updated: 8/5/2026, 4:54:44 PM
1class Solution {
2public:
3    int firstUniqueEven(vector<int>& nums) {
4        unordered_map<int, int> mpp;
5        for (int num : nums) 
6            mpp[num]++;
7        for (int num : nums) {
8            if (num % 2 == 0 && mpp[num] == 1)
9                return num;
10        }
11
12        return -1;
13    }
14};