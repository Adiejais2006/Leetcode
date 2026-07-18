// Last updated: 7/18/2026, 2:02:08 PM
class Solution {
  int helper (int no , vector<int> &nums){
    int sum = 0 ;
    int n  =nums.size();
    for(int i = 0 ;i<n;i++){
      sum = sum  + ceil((double) nums[i] / (double)no);
    }
    return sum;
  }
   public:
    int smallestDivisor(vector<int> &nums, int limit) {
        int n = nums.size();
        int low = 1;
        sort(nums.begin(), nums.end());
        int maxii = nums[n - 1];
        int high = maxii;
        int ans =maxii;
        while (low <= high) {
            int mid = (low + high )/ 2;
            if(helper(mid,nums)>limit){
                low = mid+1;
            }
            else {
              ans = min(mid,ans);
              high = mid-1;
            }
        }
        return ans ;
    }
};