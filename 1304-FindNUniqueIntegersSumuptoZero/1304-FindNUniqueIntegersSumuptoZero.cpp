// Last updated: 7/19/2026, 11:23:57 PM
1class Solution {
2public:
3    vector<int> sumZero(int n) {
4        if(n==0) {
5            return {0};
6        }
7
8      
9        vector<int> ans(n,0);
10
11        int lf = 0;
12        int rig = n-1;
13        int ps = n/2;
14
15        if(n%2!=0) {
16            ans[ps] = 0;
17            while(lf<rig) {
18                ans[lf] = -ps;
19                ans[rig]=ps;
20                ps++;
21                lf++;
22                rig--;
23            }
24
25        }
26        else if(n%2==0) {
27            while(lf<rig) {
28                ans[lf] = -ps;
29                ans[rig]=ps;
30                ps++;
31                lf++;
32                rig--;
33            }
34
35        }
36        return ans;
37    }
38};