// Last updated: 7/19/2026, 11:26:26 PM
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = ((n & 1) && i == n/2) ? 0 : (i < n/2 ? i + 1 : -(n - i));
        }
        return a;
    }
};