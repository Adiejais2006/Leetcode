// Last updated: 9/26/2026, 2:48:13 PM
1class Solution {
2public:
3    bool canConstruct(string ransomNote, string magazine) {
4        unordered_map<char, int> magaHash;
5
6        for (char c : magazine) {
7            magaHash[c]++;
8        }
9
10        for (char c : ransomNote) {
11            if (magaHash[c] <= 0) {
12                return false;
13            }
14            magaHash[c]--;
15        }
16
17        return true;
18    }
19};