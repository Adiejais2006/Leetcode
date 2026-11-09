// Last updated: 11/9/2026, 3:11:25 PM
1class Solution {
2public:
3    double findMaxAverage(vector<int>& nums, int k) {
4        int n = nums.size();
5        double l = 0.00;
6        double r = 0.00;
7        double sum = 0.00;
8        double avg = 0.00;
9    
10        while (r < k) {
11            sum += nums[r];
12            r++;
13        }
14        double ans = sum / k;
15        while (r < n) {
16            sum -= nums[l];
17            sum += nums[r];
18            avg = sum / k;
19            ans = max(ans, avg);
20            l++;
21            r++;
22        }
23        return ans;
24    }
25};