// Last updated: 11/4/2026, 7:27:28 PM
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int first = 1, last = m * n;
        while (first < last) {
            auto mid = first + (last - first) / 2, pos = 0;
            for (int i = 1; i <= m; i++) {
                pos += min(mid / i, n);
            }
            
            if (pos < k) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        
        return first;
    }
};