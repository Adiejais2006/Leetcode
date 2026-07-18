// Last updated: 7/18/2026, 2:00:53 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
         vector<int> ans(nums.size());
        int post = 0;
        int neg = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[post]=nums[i];
                post = post + 2;
            } 
            else {
            
            ans[neg] = nums[i];
            neg = neg + 2;
            }
        }
        return ans;
    }
};