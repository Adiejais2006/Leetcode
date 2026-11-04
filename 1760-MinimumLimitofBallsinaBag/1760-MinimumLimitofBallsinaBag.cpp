// Last updated: 11/4/2026, 9:40:26 PM
1class Solution {
2public:
3    bool canDivide(vector<int>& nums, int maxBalls, int maxOperations) {
4        int ops = 0;
5        for (int n : nums) {
6            ops += (n + maxBalls - 1) / maxBalls - 1;
7            if (ops > maxOperations) return false;
8        }
9        return true;
10    }
11    int minimumSize(vector<int>& nums, int maxOperations) {
12        int left = 1, right = *max_element(nums.begin(), nums.end());
13        int res = right;
14        
15        while (left < right) {
16            int mid = left + (right - left) / 2;
17            if (canDivide(nums, mid, maxOperations)) {
18                right = mid;
19                res = right;
20            } else {
21                left = mid + 1;
22            }
23        }
24        return res;
25    }
26};