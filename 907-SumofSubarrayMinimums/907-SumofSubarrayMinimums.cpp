// Last updated: 10/26/2026, 2:54:25 PM
1class Solution {
2    vector<int> nse(vector<int>& nums) {
3        int n = nums.size();
4        vector<int> a(n);
5        stack<int> st;
6        for (int i = n - 1; i >= 0; i--) {
7            while (!st.empty() && nums[i] <= nums[st.top()])
8                st.pop();
9            if (st.empty()) {
10                a[i] = n;
11            } else {
12                a[i] = st.top();
13            }
14            st.push(i);
15        }
16        return a;
17    }
18    vector<int> pse(vector<int>& nums) {
19        int n = nums.size();
20        vector<int> a(n);
21        stack<int> st;
22        for (int i = 0; i < n; i++) {
23            while (!st.empty() && nums[i] < nums[st.top()])
24                st.pop();
25            if (st.empty()) {
26                a[i] = -1;
27            } else {
28                a[i] = st.top();
29            }
30            st.push(i);
31        }
32        return a;
33    }
34
35public:
36    int sumSubarrayMins(vector<int>& arr) {
37        long long mod = 1e9 + 7;
38        vector<int> previous = pse(arr);
39        vector<int> next = nse(arr);
40        int n = arr.size();
41        long long sum = 0;
42        for (int i = 0; i < n; i++) {
43            long long left = i - previous[i];
44            long long right = next[i] - i;
45            sum = (sum + ((left * right) % mod) * arr[i] % mod) % mod;
46        }
47        return (int)sum;
48    }
49};