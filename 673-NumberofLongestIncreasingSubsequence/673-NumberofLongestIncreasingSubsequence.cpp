// Last updated: 10/27/2026, 1:14:03 PM
1class Solution {
2public:
3    int findNumberOfLIS(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> size(n, 1);
6        vector<int> cnt(n, 1);
7        int maxlen = -1;
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < i; j++) {
10                if (nums[i] > nums[j]) {
11                    if (size[i] < size[j] + 1) {
12                        size[i] = size[j] + 1;
13                        cnt[i] = cnt[j];
14                    } else if (size[i] == size[j] + 1) {
15                        cnt[i] += cnt[j];
16                    }
17                }
18            }
19            maxlen = max(maxlen, size[i]);
20        }
21        int ans = 0;
22        for (int i = 0 ;i<n ; i++){
23            if(size[i]==maxlen){
24                ans+=cnt[i];
25            }
26        }
27        return ans;
28    }
29};