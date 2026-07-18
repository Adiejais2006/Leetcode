// Last updated: 7/18/2026, 2:07:42 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i = 0;
        int n = nums.size();
        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i]) {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i  + 1 ;
    }
};