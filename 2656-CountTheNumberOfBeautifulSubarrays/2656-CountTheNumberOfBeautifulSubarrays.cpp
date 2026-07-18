// Last updated: 7/18/2026, 2:00:24 PM
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> freq;
        freq[0] = 1; 
        int xr = 0;
        long long count = 0;
        for (int num : nums) {
            xr ^= num;
            if (freq.count(xr)) {
                count += freq[xr];
            }
            freq[xr]++;
        }
        return count;
    }
};