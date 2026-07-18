// Last updated: 7/18/2026, 1:59:54 PM
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> arr;
        int bob = -1;
        int alice = -1;
        int i = 0;
        while (i < n) {
            alice = nums[i++];
            bob = nums[i++];
            arr.push_back(bob);
            arr.push_back(alice);
        }
        return arr;
    }
};