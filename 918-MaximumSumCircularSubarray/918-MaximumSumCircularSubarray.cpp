// Last updated: 11/12/2026, 7:07:08 PM
1class Solution {
2public:
3    int maxSubarraySumCircular(vector<int>& nums) {
4        int n = nums.size();
5        int maxSum = INT_MIN, currMax = 0;
6        int minSum = INT_MAX, currMin = 0;
7        int totalSum = 0;
8        for (int x : nums) {
9            totalSum += x;
10            // Maximum Kadane
11            currMax += x;
12            maxSum = max(maxSum, currMax);
13            if (currMax < 0)
14                currMax = 0;
15            // Minimum Kadane
16            currMin += x;
17            minSum = min(minSum, currMin);
18            if (currMin > 0)
19                currMin = 0;
20        }
21        // All elements are negative
22        if (maxSum < 0)
23            return maxSum;
24        return max(maxSum, totalSum - minSum);
25    }
26};