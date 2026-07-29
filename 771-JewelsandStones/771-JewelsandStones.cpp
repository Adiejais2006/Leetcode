// Last updated: 7/29/2026, 8:26:52 PM
1class Solution {
2public:
3    int numJewelsInStones(string jewels, string stones) {
4        unordered_set<char> mpp;
5        for (auto it : jewels) {
6            mpp.insert(it);
7        }
8        int cnt = 0;
9        for (auto it : stones) {
10            if (mpp.count(it) != 0)
11                cnt++;
12        }
13        return cnt;
14    }
15};