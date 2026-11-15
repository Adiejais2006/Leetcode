// Last updated: 11/15/2026, 2:31:53 PM
1class Solution {
2    bool checker(int i, int j, vector<int> nums) {
3        int mini = INT_MAX, maxi = INT_MIN;
4        int n = j - i + 1;
5        for (int k = i; k <= j; k++) {
6            mini = min(mini, nums[k]);
7            maxi = max(maxi, nums[k]);
8        }
9        if (mini == maxi)
10            return true;
11        // 1 2 3 4   (4-1)/2==0 yaani ki n-1 spots ho skate hai
12        // agr 1 2 6 hota to (6-1)/2!=0 is liye baat hi nahi skte us d ke saath
13        // since d proper hona chahiye perfect
14        if ((maxi - mini) % (n - 1) != 0)
15            return false;
16        int d = (maxi - mini) / (n - 1);
17        vector<int> vis(n, 0);
18        for (int k = i; k <= j; k++) {
19            int pos = (nums[k] - mini) / d;
20            // ham kisi bhi element ki pos nikal sakte hai agr d pata ho jaise
21            // 1 2 3 4 for 2 (2-1)/1=1 yaani uski pos 1 hai jo ki correct hai
22            if ((nums[k] - mini) % d != 0 || vis[pos])
23                return false;
24            vis[pos] = 1;
25        }
26        return true;
27    }
28
29public:
30    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
31                                          vector<int>& r) {
32        int n = l.size();
33        vector<bool> ans(n);
34        for (int i = 0; i < n; i++) {
35            ans[i] = checker(l[i], r[i], nums);
36        }
37        return ans;
38    }
39};