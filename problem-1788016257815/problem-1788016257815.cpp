// Last updated: 8/29/2026, 8:40:57 PM
1class Solution {
2public:
3    vector<string> largestString(vector<int>& nums) {
4        vector<string> answer;
5        for (int x : nums) {
6            string s;
7            int zCount = x >> 25;
8            s.append(zCount, 'z');
9            int remaining = x & ((1 << 25) - 1);
10            for (int i = 24; i >= 0; i--) {
11                if (remaining & (1 << i))
12                    s += char('a' + i);
13            }
14            answer.push_back(s);
15        }
16        return answer;
17    }
18};