// Last updated: 7/29/2026, 7:57:18 PM
1class Solution {
2public:
3    int minMoves(int target, int maxDoubles) {
4        int steps = 0;
5        while (target != 1) {
6            if (maxDoubles == 0) {
7                steps += (target - 1); // Add all remaining decrements at once
8                break;                 // We are done!
9            }
10            if (target % 2 == 1) {
11                target -= 1;
12            } else {
13                target /= 2;
14                maxDoubles--;
15            }
16            steps++;
17        }
18        
19        return steps; // Return steps directly
20    }
21};
22