// Last updated: 7/18/2026, 2:00:27 PM
class Solution {
public:
    int countDigits(int num) {
        int cnt = 0;
        int orig = num;
        while (num != 0) {
            int r = num % 10;
            if (orig % r == 0)
                cnt++;
            num = num / 10;
        }
        return cnt;
    }
};