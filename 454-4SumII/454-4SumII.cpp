// Last updated: 10/18/2026, 10:53:32 PM
1class Solution {
2public:
3    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
4        map<int,int> mp;
5        for(int k : nums3)
6            for(int l : nums4)
7                mp[k + l]++;
8        int count = 0;
9        for(int i : nums1)
10            for(int j : nums2)
11                        count += mp[-(i + j)];
12        return count;
13    }
14};