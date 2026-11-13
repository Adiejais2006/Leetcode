// Last updated: 11/13/2026, 1:44:11 PM
1class Solution {
2public:
3    int largestSumAfterKNegations(vector<int>& nums, int k) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6        for (int i = 0; i < n; i++) {
7            if (k == 0)
8                break;
9            if (nums[i] < 0) {
10                nums[i] = -nums[i];
11                k--;
12            }
13        }
14        int sum = 0 ;
15        for(auto it:nums) sum+=it;
16        if(k%2==1){
17            int mini = INT_MAX;
18            for(auto it:nums){
19                mini = min(mini,it);
20            }
21            sum-=2*mini;
22        }
23        return sum ;
24    }
25};