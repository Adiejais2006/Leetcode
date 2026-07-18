// Last updated: 7/18/2026, 1:58:49 PM
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long ans =0;
        for(int i =0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
                ans+=( nums[i]- nums[i+1]);
            }
        }
        return ans;
    }
};