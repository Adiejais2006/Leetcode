// Last updated: 7/18/2026, 2:01:24 PM
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
            int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0 ; i<n ;i++){
            if(nums[i]==target){
                int a = abs(i-start);
                ans = min(ans,a);
            }
        }
        return ans;
    }
};