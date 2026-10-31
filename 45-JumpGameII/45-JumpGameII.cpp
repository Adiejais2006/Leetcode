// Last updated: 10/31/2026, 9:42:38 PM
1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int near = 0, far = 0, jumps = 0;
5        while (far < nums.size() - 1) {
6            int farthest = 0;
7            for (int i = near; i <= far; i++) {
8                farthest = max(farthest, i + nums[i]);
9            }
10            near = far + 1;
11            far = farthest;
12            jumps++;
13        }
14
15        return jumps;        
16    }
17};