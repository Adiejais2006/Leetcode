// Last updated: 10/31/2026, 10:42:48 PM
1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int n = haystack.size();
5        int m = needle.size();
6        for(int i = 0 ; i<=n-m ; i++){
7            if(haystack.substr(i,m)==needle) return i;
8        }
9        return -1;
10    }
11};