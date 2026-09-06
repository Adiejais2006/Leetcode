// Last updated: 9/6/2026, 5:19:30 PM
1class Solution {
2public:
3    vector<int> countBits(int n) {
4        vector<int>ans(n+1,0);
5        for(int i=i;i<=n;i++){
6            ans[i]=ans[i>>1]+(i&1);
7        }
8        return ans;
9        
10    }
11};