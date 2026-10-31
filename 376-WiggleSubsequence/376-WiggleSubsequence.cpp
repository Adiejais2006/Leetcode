// Last updated: 10/31/2026, 10:44:34 PM
1class Solution {
2public:
3    int wiggleMaxLength(vector<int>& nums) {
4        int n = nums.size();
5        if(n < 2) return n;
6        int prev = nums[1] - nums[0];
7        int cnt = prev != 0 ? 2 : 1;
8        for(int i = 2; i < n; i++){
9            int diff = nums[i] - nums[i-1];
10            if((diff > 0 && prev <= 0) || (diff < 0 && prev >= 0)){
11                cnt++;
12                prev = diff;
13            }
14        }
15        return cnt;
16    }
17};