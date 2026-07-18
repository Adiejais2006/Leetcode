// Last updated: 7/18/2026, 2:05:20 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0 ; i<n ; i++) {
            mpp[nums[i]] ++;

        }
        vector<int> ans;
        for(auto it :mpp){
            if(it.second > n/3) ans.push_back(it.first);
            if(ans.size()==2) break;
        }

        return ans ;
    }
};