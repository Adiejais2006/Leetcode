// Last updated: 11/1/2026, 2:26:23 PM
1class Solution {
2public:
3    string sortSentence(string s) {
4        stringstream ss(s);
5        string word;
6        vector<string> a(10);
7        while (ss >> word) {
8            int size = word.size();
9            int number = word[size - 1] - '0';
10            word.pop_back();
11            a[number] = word;
12        }
13        string ans = "";
14        for (int i = 0; i < 10; i++) {
15            if (a[i] != "") {
16                ans += a[i] + " ";
17            }
18        }
19        ans.pop_back();
20        return ans;
21    }
22};