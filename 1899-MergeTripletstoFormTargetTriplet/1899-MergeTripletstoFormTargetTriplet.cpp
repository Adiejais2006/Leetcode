// Last updated: 11/16/2026, 6:14:38 PM
1class Solution {
2public:
3    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
4        bool first = false; 
5        bool second = false; 
6        bool third = false; 
7        int n = triplets.size(); 
8        for (int i = 0; i < n; i++) {
9            if (triplets[i][0] == target[0]) {
10                if (triplets[i][1] <= target[1] && 
11                    triplets[i][2] <= target[2]) {
12                    first = true; 
13                }
14            }
15            if (triplets[i][1] == target[1]) {
16                if (triplets[i][0] <= target[0] && 
17                    triplets[i][2] <= target[2]) {
18                    second = true; 
19                }
20            }
21            if (triplets[i][2] == target[2]) {
22                if (triplets[i][0] <= target[0] && 
23                    triplets[i][1] <= target[1]) {
24                    third = true;
25                }
26            }
27        }
28        return first && second && third; 
29    }
30};