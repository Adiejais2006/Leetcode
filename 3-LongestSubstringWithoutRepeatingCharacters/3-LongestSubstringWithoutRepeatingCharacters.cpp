// Last updated: 7/18/2026, 2:08:10 PM
class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int n = nums.size();
        unordered_map<char, int> mpp;
        int left = 0;
        int right = 0;
        int ans = 0;

        while (right < n) {
            mpp[nums[right]]++;

            while (mpp[nums[right]] > 1) {
                mpp[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
