// Last updated: 11/15/2026, 1:56:03 PM
1class Solution {
2public:
3    int numSplits(string s) {
4        int n = s.size();
5        vector<int> rightside(26, 0);
6        vector<int> leftside(26, 0);
7        int leftunique = 0;
8        int rightunique = 0;
9        int ans = 0 ; 
10        for (int i = 0; i < n; i++) {
11            if (rightside[s[i] - 'a'] == 0) {
12                rightunique++;
13            }
14            rightside[s[i] - 'a']++;
15        }
16
17        for (int i = 0; i < n - 1; i++) {
18            int idx = s[i] - 'a';
19
20            if (leftside[idx] == 0) {
21                leftunique++;
22            }
23            leftside[idx]++;
24
25            rightside[idx]--;
26            if (rightside[idx] == 0) {
27                rightunique--;
28            }
29            if(leftunique==rightunique)ans++;
30        }
31        return ans ;
32    }
33};