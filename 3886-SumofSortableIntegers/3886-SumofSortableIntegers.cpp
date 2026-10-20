// Last updated: 10/20/2026, 3:12:09 PM
1class Solution {
2public:
3    int sortableIntegers(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> desc(n);
7        for (int i = 1; i < n; i++)
8            desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);
9        vector<int> premax(n), sufmin(n);
10        inclusive_scan(nums.begin(), nums.end(), premax.begin(),
11                       [](int a, int b) { return max(a, b); });
12        inclusive_scan(nums.rbegin(), nums.rend(), sufmin.rbegin(),
13                       [](int a, int b) { return min(a, b); });
14        vector<bool> cut(n, true);
15        for (int m = 1; m < n; m++)
16            cut[m] = premax[m - 1] <= sufmin[m];
17
18        auto rotatable = [&](int l, int r) {
19            return desc[r] - desc[l] + (nums[r] > nums[l]) <= 1;
20        };
21        auto sortable = [&](int k) {
22            for (int l = 0; l < n; l += k)
23                if (!cut[l] || !rotatable(l, l + k - 1))
24                    return false;
25            return true;
26        };
27
28        vector<int> divisors;
29        for (int k = 1; k <= n; k++)
30            if (n % k == 0)
31                divisors.push_back(k);
32        auto good = divisors | views::filter(sortable);
33        return accumulate(good.begin(), good.end(), 0);
34    }
35};