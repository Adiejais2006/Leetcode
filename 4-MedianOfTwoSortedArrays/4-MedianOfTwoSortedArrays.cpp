// Last updated: 7/18/2026, 2:08:09 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, o = 0, t = 0;
        int count = (n + m) / 2;

        while (count>=0) {
             t = o;
            if (i != n && j != m) {
                if (nums1[i] > nums2[j]) {
                    o = nums2[j++];
                } else {
                    o = nums1[i++];
                }
            } else if (i < n) {
                o = nums1[i++];
            } else {
                o = nums2[j++];
            }
            count--;
        }

        if ((n + m) % 2 == 1) {
            return (double)(o);
        } else {
            double ans = (double)(o) + (double)(t);
            return ans / 2.0;
        }
    }
};