// Last updated: 7/18/2026, 2:07:02 PM
class Solution {
public:
    int climbStairs(int n) {
      
        if (n == 1 || n == 0)
            return 1;
        int a = 1;
        int b = 1;
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            int curr = a + b;
            a = b;
            b = curr;
            ans = curr;
        }
        return ans;
    }
};