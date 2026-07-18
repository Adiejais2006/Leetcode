// Last updated: 7/18/2026, 2:08:02 PM
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long n = x;
        long long rev = 0;
        while (n != 0) {
            long long r = n % 10;
            rev = rev * 10 + r;
            n = n / 10;
        }

        return (x == rev);
    }
};