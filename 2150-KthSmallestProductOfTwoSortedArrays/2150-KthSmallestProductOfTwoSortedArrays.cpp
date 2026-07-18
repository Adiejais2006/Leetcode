// Last updated: 7/18/2026, 2:01:08 PM
class Solution {
public:
    long long countLessEqual(const vector<int>& a, const vector<int>& b, long long x) {
        long long cnt = 0;
        int n = b.size();

        for (long long num : a) {
            if (num > 0) {
                int l = 0, r = n - 1, pos = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (num * 1LL * b[mid] <= x) {
                        pos = mid;
                        l = mid + 1;
                    } else r = mid - 1;
                }
                cnt += (pos + 1);
            } 
            else if (num < 0) {
                int l = 0, r = n - 1, pos = n;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (num * 1LL * b[mid] <= x) {
                        pos = mid;
                        r = mid - 1;
                    } else l = mid + 1;
                }
                cnt += (n - pos);
            } 
            else {
                if (x >= 0) cnt += n;
            }
        }
        return cnt;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10, high = 1e10;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};