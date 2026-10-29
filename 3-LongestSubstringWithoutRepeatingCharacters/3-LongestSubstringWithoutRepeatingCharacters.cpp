// Last updated: 10/29/2026, 2:51:14 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n = s.size();
5        int l = 0;
6        int r = 0;
7        unordered_map<int, int> mpp;
8        int ans = 0 ; 
9        while (r < n) {
10            mpp[s[r]]++;
11            while (mpp[s[r]]>1){
12                mpp[s[l]]--;
13                l++;
14            }
15            ans=max(ans,r-l+1);
16            r++;
17        }
18        return ans ;
19    }
20};