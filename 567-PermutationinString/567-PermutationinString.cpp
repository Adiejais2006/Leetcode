// Last updated: 7/19/2026, 11:04:21 PM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int m = s1.size(); // jiska dhundna hai
5        int n = s2.size(); // jisme dhundna hai 
6        sort(s1.begin() , s1.end());
7        for(int i = 0 ; i<n-m+1 ; i++){
8            string ans ="";
9            for(int j = i ; j < i + m ; j++){
10                ans+= s2[j];
11                if(ans.size()==m)
12                sort(ans.begin() , ans.end());
13                if(ans==s1) return true;
14            }
15        }
16
17        return false;
18    }
19};