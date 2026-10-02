// Last updated: 10/2/2026, 5:42:31 PM
1class Solution {void func(int open, int close, int n, string s, vector<string> &ans) {
2        if (open == close && (open + close) == 2 * n) {
3            ans.push_back(s); 
4            return; 
5        }
6        
7        if (open < n) {
8            func(open + 1, close, n, s + '(', ans); 
9        }      
10        if (close < open) {
11            func(open, close + 1, n, s + ')', ans); 
12        }
13    }
14public:
15    vector<string> generateParenthesis(int n) {
16          vector<string> ans; 
17        func(0, 0, n, "", ans); 
18        return ans; 
19    }
20};