// Last updated: 7/20/2026, 10:12:10 PM
1class Solution {
2public:
3    string interpret(string command) {
4
5        string res = "";
6
7        for(int i =0; i < command.size();) {
8
9            if(command[i]=='G') {
10                res+="G";
11                i++;
12            }
13            else if(command[i]=='(' && command[i+1]==')') {
14                res+='o';
15                i+=2;
16            }
17            else {
18                res+="al";
19                i+=4;
20            }
21        }
22        return res;
23    }
24};