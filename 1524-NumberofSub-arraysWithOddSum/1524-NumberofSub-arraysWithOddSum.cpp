// Last updated: 11/15/2026, 1:19:23 PM
1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr) {
4        const int MOD = 1e9 + 7;
5        int count = 0, prefixSum = 0;
6        int oddCount = 0, evenCount = 1;
7        for (int num : arr) {
8            prefixSum += num;
9            if (prefixSum % 2 == 0) {
10                count += oddCount;
11                evenCount++;
12            } else {
13                count += evenCount;
14                oddCount++;
15            }
16            count %= MOD;  
17        }
18        return count;
19    }
20};