// Last updated: 9/3/2026, 4:15:22 PM
1class Solution {
2    vector<int> ns(vector<int>& nums) {
3        int n = nums.size();
4        vector<int> ans(n);
5        stack<int> st;
6        for (int i = n - 1; i >= 0; i--) {
7            while (!st.empty() && nums[st.top()] >= nums[i]) {
8                st.pop();
9            }
10            if (st.empty())
11                ans[i] = n;
12            else
13                ans[i] = st.top();
14            st.push(i);
15        }
16        return ans;
17    }
18    vector<int> ps(vector<int>& nums) {
19        int n = nums.size();
20        vector<int> ans(n);
21        stack<int> st;
22        for (int i = 0; i < n; i++) {
23            while (!st.empty() && nums[st.top()] > nums[i]) {
24                st.pop();
25            }
26            if (st.empty())
27                ans[i] = -1;
28            else
29                ans[i] = st.top();
30            st.push(i);
31        }
32        return ans;
33    }
34
35public:
36    int sumSubarrayMins(vector<int>& nums) {
37        vector<int> nse = ns(nums);
38        vector<int> pse = ps(nums);
39        long long ans = 0;
40        long long mod = 1e9 + 7;
41        int n = nums.size();
42        for (int i = 0; i < n; i++) {
43            long long left = i - pse[i];
44            long long right = nse[i] - i;
45            ans = (ans + (left * right % mod) * nums[i]) % mod;
46        }
47        return (int)ans;
48    }
49};