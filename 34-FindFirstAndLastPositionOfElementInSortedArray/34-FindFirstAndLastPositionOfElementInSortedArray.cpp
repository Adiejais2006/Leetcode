// Last updated: 7/18/2026, 2:07:33 PM
class Solution { int lower(int low, int high, vector<int> &nums , int target) {
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                if (nums[mid] == target) ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }

    int upper(int low, int high, vector<int> &nums , int target) {
        int ans = nums.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
          int n = nums.size();
        int start = lower(0, n - 1, nums , target);
        if (start == -1) return {-1, -1}; // target not found
        int end = upper(0, n - 1, nums , target);
        return {start, end - 1};
    }
};