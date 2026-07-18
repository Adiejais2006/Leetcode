// Last updated: 7/18/2026, 2:07:15 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          int sum = 0 ;
        int n = nums.size();
        if(n==0) return 0 ;
        int ans = INT_MIN;
        for(int i =0 ; i<n ; i++){

            sum = sum +nums[i];
            if(sum>ans) ans = max(ans , sum);
            if(sum<0) sum = 0 ;

        }

        return ans ;
    }
};