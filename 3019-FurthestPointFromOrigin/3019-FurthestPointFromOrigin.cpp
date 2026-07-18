// Last updated: 7/18/2026, 1:59:58 PM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blank = 0;

        for(char ch : moves) {
            if(ch == 'L') left++;
            else if(ch == 'R') right++;
            else blank++;
        }

        return abs(left - right) + blank;
    }
};