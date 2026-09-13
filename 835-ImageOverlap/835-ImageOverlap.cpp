// Last updated: 9/13/2026, 12:19:56 PM
1class Solution {
2public:
3    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
4        int n = img1.size();
5        vector<pair<int, int>> ones1, ones2;
6        for(int r = 0; r < n; r++){
7            for(int c = 0; c < n; c++){
8                if(img1[r][c] == 1)
9                    ones1.push_back({r, c});
10                if(img2[r][c] == 1)
11                    ones2.push_back({r, c});
12            }
13        }
14        unordered_map<int, int> frequency;
15        int maxOverlap = 0;
16        for(auto [r1, c1] : ones1){
17            for(auto [r2, c2] : ones2){
18                int dr = r1 - r2;
19                int dc = c1 - c2;
20                int key = dr * 100 + dc;
21                frequency[key]++;
22                maxOverlap = max(maxOverlap, frequency[key]);
23            }
24        }
25      return maxOverlap;
26    }
27};