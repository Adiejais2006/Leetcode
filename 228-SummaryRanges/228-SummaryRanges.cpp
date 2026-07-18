// Last updated: 7/18/2026, 2:05:21 PM
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        vector<string> ans;
        int n = nums.size();
        int startindx = 0;
        string start = to_string(nums[0]);
        int i = 0;
        for (i; i < n - 1; i++) {
            if (nums[i] != nums[i + 1] - 1) {
                if (i - startindx > 0)
                    ans.push_back(start + "->" + to_string(nums[i]));
                else
                    ans.push_back(start);
                start = to_string(nums[i + 1]);
                startindx = i + 1;
            }
        }
        if (i - startindx > 0)
            ans.push_back(start + "->" + to_string(nums[n - 1]));
        else
            ans.push_back(start);

        return ans;
    }
};