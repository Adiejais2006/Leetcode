// Last updated: 7/18/2026, 2:03:07 PM
class Solution { long long helper(int no, vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + ((nums[i] + no - 1) / no);
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& nums, int h) {
         int n = nums.size();
        int low = 1;
        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            high = max(high, nums[i]);
        }
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (helper(mid, nums) > h) {
                low = mid + 1;
            } else {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        return ans;
    }
};