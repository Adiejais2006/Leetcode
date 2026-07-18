// Last updated: 7/18/2026, 2:01:53 PM
class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int tot = 0;
        
        for (int x : cardPoints) {
            tot += x;
        }
        
        if (k == n) {
            return tot;
        }
        
        int sz = n - k;
        int curr = 0;
        
        for (int i = 0; i < sz; ++i) {
            curr += cardPoints[i];
        }
        
        int mn = curr;
        
        for (int i = sz; i < n; ++i) {
            curr += cardPoints[i] - cardPoints[i - sz];
            if (curr < mn) {
                mn = curr;
            }
        }
        
        return tot - mn;
    }
};