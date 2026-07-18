// Last updated: 7/18/2026, 2:05:39 PM
class Solution {
    int summer(int n) {
        int sum = 0;
        while (n != 0) {
            int r = n % 10;
            sum += r * r;
            n = n / 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        unordered_map<int, int> mpp;

        while (n != 1) {
            if (mpp.find(n) != mpp.end())
                return false;
            mpp[n] = 1;
            n = summer(n);
        }
        return true;
    }
};