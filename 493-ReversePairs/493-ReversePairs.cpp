// Last updated: 7/18/2026, 2:04:21 PM
class Solution {void counter(int low, int mid, int high, vector<int> &nums, int &count) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)nums[i] > 2 * (long long )nums[right]) {
                right++;
            }
            count = count + right - mid - 1;
        }
        return;
    }
    void merge(int low, int mid, int high, vector<int> &nums, int &count) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= high) {
            if (nums[left] > nums[right]) {
                temp.push_back(nums[right]);
                right++;
            } else if (nums[right] >= nums[left]) {
                temp.push_back(nums[left]);
                left++;
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        return;
    }
    void mergesorter(int low, int high, vector<int> &nums, int &count) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergesorter(low, mid, nums, count);
        mergesorter(mid + 1, high, nums, count);
        counter(low, mid, high, nums, count);
        merge(low, mid, high, nums, count);
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        mergesorter(0, n - 1, nums, count);
        return count; 
    }
};