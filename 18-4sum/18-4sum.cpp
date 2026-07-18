// Last updated: 7/18/2026, 2:07:51 PM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                int start = j + 1;
                int end = n - 1;
           
                while (start < end) {
long long sum = (long long)nums[i] + nums[j] + nums[start] + nums[end];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[start],
                                            nums[end]};
                        ans.push_back(temp);
                        start++;
                        while(start<end && nums[start]==nums[start-1]) start++;
                        end--;
                        while(start<end && nums[end]==nums[end+1]) end--;
                    }
                    else if ( sum>target) end--;
                    else start++;
                    
                }
            }
        }
        return ans;
    }
};