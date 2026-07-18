// Last updated: 7/18/2026, 1:58:51 PM
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> gcd;
        int maxu = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            maxu = max(maxu, nums[i]);
            int a = std::gcd(nums[i], maxu);
            gcd.push_back(a);
        }
        long long sum = 0;
        sort(gcd.begin(), gcd.end());
        int i = 0;
        int j = gcd.size() - 1;
        while (i < j) {
            int a = std::gcd(gcd[i], gcd[j]);
            sum += a;
            i++;
            j--;
        }
        return sum;
    }
};