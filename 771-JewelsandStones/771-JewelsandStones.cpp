// Last updated: 7/29/2026, 8:24:33 PM
1class Solution {
2public:
3    int numJewelsInStones(string jewels, string stones) {
4
5        int count = 0;
6
7        for(int i = 0; i < stones.length(); i++) {
8
9            for(int j = 0; j < jewels.size();  j++) {
10
11                if(stones[i]==jewels[j]) {
12                    count++;
13                }
14            }
15        }
16        return count;
17    }
18};