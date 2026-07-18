// Last updated: 7/18/2026, 2:06:54 PM
class Solution {
public:
    bool search(vector<int>& arr, int target) {
         int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            // left half sorted hai kyoki low se mid bda haai
            if (arr[mid] == target) return true;
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= target && arr[mid] >= target) {
                    high = mid - 1;
                } else
                    low = mid + 1;
            }
            // right half sorted
            else  { // YAHA PR ELSE IF LAGA HUA THA JISKI WAJAH SE TL EAA RHA THA
                if (arr[mid] <= target && arr[high] >= target) {
                    low = mid + 1;
                } else
                    high = mid - 1;
            }
        }

        return false;
    }
};