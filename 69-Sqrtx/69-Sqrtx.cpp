// Last updated: 7/18/2026, 2:07:04 PM
class Solution {
public:
    int mySqrt(int n) {
         long long low = 1;
        long long high = n ;
        long long ans = 0;
     
        while (low <= high) {
            long long mid = (low + high) / 2;
            if ((mid * mid) <= n) {
                ans = mid;
                low = mid + 1;
            } else if ((mid * mid) > n) {
                high = mid - 1;
            }
        }

        return ans;
    }
};