// Last updated: 9/26/2026, 2:41:19 PM
1class Solution {
2public:
3    string evaluate(string s, vector<vector<string>>& knowledge) {
4        unordered_map<string, string> map;
5        for (auto& k : knowledge) map[k[0]] = k[1];
6        string ans, key;
7        bool inside = false;
8        for (char c : s) {
9            if (c == '(') { inside = true; key = ""; }
10            else if (c == ')') {
11                inside = false;
12                ans += map.count(key) ? map[key] : "?";
13            }
14            else if (inside) key += c;
15            else ans += c;
16        }
17        return ans;
18    }
19};