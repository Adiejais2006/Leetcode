// Last updated: 7/18/2026, 2:05:07 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for(int i = 0; i <= n; i++) {
            if(mpp.find(i) == mpp.end()) return i;
        }

        return -1;   
    }
};