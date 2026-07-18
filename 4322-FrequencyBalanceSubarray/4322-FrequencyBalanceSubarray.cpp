// Last updated: 7/18/2026, 1:58:33 PM
class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            unordered_map<int, int> freq;
            int maxf = 0;
            for (int j = i; j < n; j++) {
                int old = mpp[nums[j]];
                if (old > 0)
                    freq[old]--;
                mpp[nums[j]]++;
                freq[mpp[nums[j]]]++;
                maxf = max(maxf, mpp[nums[j]]);
                int cntmaxf = freq[maxf];
                int size = mpp.size();
                if (size == 1) {
                    ans = max(ans, j - i + 1);
                }

                if (mpp.size() > 1 && maxf % 2 == 0 && size > cntmaxf &&
                    freq[maxf / 2] == size - cntmaxf) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};