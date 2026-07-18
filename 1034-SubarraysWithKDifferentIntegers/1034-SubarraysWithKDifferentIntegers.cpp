// Last updated: 7/18/2026, 2:02:45 PM
class Solution {
private:
    int solve(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> m;
        int l = 0, ans = 0;

        for (int r = 0; r < n; ++r) {
            m[nums[r]]++;
            
            while (m.size() > k) {
                m[nums[l]]--;
                if (m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l++;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }

public:
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};