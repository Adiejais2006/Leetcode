// Last updated: 10/18/2026, 9:45:55 PM
1class Solution {
2public:
3    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
4        vector<int> ans;
5        int n = nums.size();
6        int l = 0;
7        int r = 0;
8        vector<int> negfreq(51, 0);
9        int neg = 0;
10        while (r < k) {
11            if (nums[r] < 0) {
12                neg++;
13                negfreq[nums[r] * -1]++;
14            }
15            r++;
16        }
17        if (neg >= x) {
18            int cnt = 0;
19            for (int i = 50; i >= 0; i--) {
20                if (negfreq[i] > 0) {
21                    cnt += negfreq[i];
22                }
23                if (cnt >= x) {
24                    ans.push_back(-1 * i);
25                    break;
26                }
27            }
28        } else
29            ans.push_back(0);
30        while (r < n) {
31            if (nums[l] < 0) {
32                negfreq[-1 * nums[l]]--;
33                neg--;
34            }
35            if (nums[r] < 0) {
36                negfreq[-1 * nums[r]]++;
37                neg++;
38            }
39            if (neg < x)
40                ans.push_back(0);
41            else {
42                int cnt = 0;
43                for (int i = 50; i >= 0; i--) {
44                    if (negfreq[i] > 0) {
45                        cnt += negfreq[i];
46                    }
47                    if (cnt >= x) {
48                        ans.push_back(-1 * i);
49                        break;
50                    }
51                }
52            }
53            r++;
54            l++;
55        }
56        return ans;
57    }
58};