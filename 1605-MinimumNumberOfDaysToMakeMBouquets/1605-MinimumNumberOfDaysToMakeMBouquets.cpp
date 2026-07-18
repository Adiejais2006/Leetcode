// Last updated: 7/18/2026, 2:01:47 PM
class Solution {
    bool bloomed(int number, vector<int>& nums, int k, int m) {
        long long n = nums.size();
        long long cntflower = 0;
        long long bouquet = 0;
        for (long long i = 0; i < n; i++) {
            if (nums[i] <= number) {
                cntflower++;
            } else {
                bouquet = bouquet + cntflower / k;
                cntflower = 0;
            }
        }
        bouquet = bouquet + cntflower / k;
        return bouquet >= m;
    }

public:
    int minDays(vector<int>& nums, int m, int k) {
    long long n = nums.size();
    if ((long long)m * k > n) return -1;

    int low = *min_element(nums.begin(), nums.end());
    int high = *max_element(nums.begin(), nums.end());
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (bloomed(mid, nums, k, m)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

};