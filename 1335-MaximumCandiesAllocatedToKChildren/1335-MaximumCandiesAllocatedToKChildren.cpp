// Last updated: 7/18/2026, 2:02:15 PM
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int n = candies.size();
        int ans = 0;
        int high = INT_MIN;
        for (int i = 0; i < n; i++)
            high = max(high, candies[i]);

        while (low <= high) {
            int mid = (low + high) / 2;
            // check if possible
          long long child = 0;
            for (int i = 0; i < n; i++) {
                child += candies[i] / mid;
            }

            if (child >= k) {
                ans = mid;
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};