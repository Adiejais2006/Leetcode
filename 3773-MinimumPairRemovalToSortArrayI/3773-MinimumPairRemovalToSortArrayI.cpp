// Last updated: 7/18/2026, 1:59:32 PM
class Solution {
    bool isSorted(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }

    int minpos(vector<int>& nums) {
        int asum = INT_MAX;
        int pos = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (sum < asum) {
                asum = sum;
                pos = i;
            }
        }
        return pos;
    }
    void mergePair(vector<int>& v, int pos) {
        v[pos] += v[pos + 1];
        v.erase(v.begin() + pos + 1);
    }

public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while (!is_sorted(nums.begin(), nums.end())) {

           
            mergePair(nums, minpos(nums));

            cnt++;
        }

        return cnt;
    }
};