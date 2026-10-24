// Last updated: 10/24/2026, 2:15:41 PM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int x) {
4        int n = nums.size();
5        int total = accumulate(nums.begin(), nums.end(), 0);
6        int target = total - x;
7
8        if(target < 0) return -1;
9        if(target == 0) return n;
10        int left = 0;
11        int sum = 0;
12        int longest = -1;
13        for(int right = 0; right < n; right++){
14            sum += nums[right];
15            while(left <= right && sum > target){
16                sum -= nums[left++];
17            }
18            if(sum == target){
19                longest = max(longest, right - left + 1);
20            }
21        }
22
23        return longest == -1 ? -1 : n - longest;
24    }
25};