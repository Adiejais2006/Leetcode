// Last updated: 7/18/2026, 1:58:23 PM
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int middle = n/2;
        int cnt = 0 ;
        for(auto it:nums){
            if(it==nums[middle])cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
};