// Last updated: 9/11/2026, 12:41:18 PM
1class Solution {
2public:
3    int totalNumbers(vector<int>& digits) {
4        int freq[10] = {0};
5        for (int d : digits) freq[d]++;
6        int count = 0;
7
8        for(int h = 1; h <= 9; h++){
9            if (freq[h] == 0) continue;
10            freq[h]--;
11            for(int t = 0; t <= 9; t++){
12                if (freq[t] == 0) continue;
13                freq[t]--;
14                for(int u = 0; u <= 8; u += 2){
15                    if (freq[u] > 0) count++;
16                }
17                freq[t]++;
18            }
19            freq[h]++;
20        }
21        return count;
22    }
23};