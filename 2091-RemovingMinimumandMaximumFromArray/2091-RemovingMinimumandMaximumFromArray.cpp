// Last updated: 8/30/2026, 8:18:10 PM
1class Solution {
2public:
3    int minimumDeletions(vector<int>& nums) {
4        int n = nums.size();
5        int left = 0;
6        int right = 0;
7        
8        for (int i = 1; i < n; i++) {
9            if (nums[i] < nums[left])
10                left = i;
11                
12            if (nums[i] > nums[right])
13                right = i;
14        }
15        
16        if (left < right)
17            swap(left, right);
18            
19        int ans = n;
20        
21        for (int i = 0; i <= n; i++) {
22            int extra = 0;
23            
24            if (right >= i)
25                extra = n - right;
26            else if (left >= i)
27                extra = n - left;
28                
29            ans = min(ans, i + extra);
30        }
31        
32        return ans;
33    }
34};