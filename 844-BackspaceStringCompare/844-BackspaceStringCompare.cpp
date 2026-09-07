// Last updated: 9/8/2026, 12:49:12 AM
1class Solution {
2public:
3    bool backspaceCompare(string s, string t) {
4
5        stack<char> st1;
6        stack<char> st2;
7
8        for(char ch : s){
9            if(ch != '#'){
10                st1.push(ch);
11            }
12            else{
13                if(!st1.empty()){
14                    st1.pop();
15
16                }
17            }
18        }
19        for(char ch : t){
20            if(ch != '#'){
21                st2.push(ch);
22            }
23            else{
24                if(!st2.empty()){
25                    st2.pop();
26
27                }
28            }
29        }
30
31        return st1 == st2;
32                
33
34        
35    }
36};