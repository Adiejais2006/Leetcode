// Last updated: 10/26/2026, 12:16:25 AM
1class Solution {
2public:
3    long long maximizeSum(vector<int>& nums, int k) {
4        long long sumi = 0;
5        priority_queue<int> pq;
6        for (int i = 0; i < nums.size(); i++) {
7            string s = to_string(nums[i]);
8            sort(s.rbegin(), s.rend());
9            int dingu = stoi(s);
10            pq.push(dingu - nums[i]);
11            sumi += nums[i];
12        }
13        for (int i = 0; i < k; i++) {
14            if (pq.top() < 0)
15                break;
16            int love = pq.top();
17            pq.pop();
18            sumi += love;
19        }
20        return sumi;
21    }
22};