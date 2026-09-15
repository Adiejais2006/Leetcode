// Last updated: 9/15/2026, 2:31:21 PM
1class Solution {
2public:
3    int maxPalindromes(string s, int k) {
4        int n = s.size(), ans = 0, end = -1;
5        for(int i = 0; i < n; i++){
6            // Even Length first, then Odd Length
7            for(int l : {i - 1, i}){
8                int r = i;
9                // expand outward from the center
10                while(l >= 0 && r < n && s[l] == s[r]){
11                    if(r - l + 1 >= k && l > end){
12                        ans++;
13                        end = r;
14                        break;
15                    }
16                    l--, r++;
17                }
18            }
19        }
20        return ans;
21    }
22};