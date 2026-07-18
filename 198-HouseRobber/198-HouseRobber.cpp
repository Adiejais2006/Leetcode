// Last updated: 7/18/2026, 2:05:43 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2= 0;
        for (int i = 1; i < n; i++) {
            int take = nums[i] + ((i > 1) ? prev2 : 0);
            int nottake = prev;
            int cur =  max(take, nottake);
            prev2=prev;
            prev =cur;
        }
        return prev;
    }
};