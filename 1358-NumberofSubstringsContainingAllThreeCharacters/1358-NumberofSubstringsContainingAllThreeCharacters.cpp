// Last updated: 11/1/2026, 3:11:08 PM
1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int n = s.size();
5        int l = 0  ;
6        int r = 0 ;
7        vector<int>hash(3,0);
8        int ans = 0 ; 
9        while(r<n){
10            hash[s[r]-'a']++;
11            while(hash[0]>0 && hash[1] && hash[2]>0){
12                ans+= n-r;
13                hash[s[l]-'a']--;
14                l++;
15            }
16            r++;
17        }
18        return ans;
19    }
20};