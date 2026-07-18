// Last updated: 7/18/2026, 2:05:53 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) /2;
            // left half sorted
            if(nums[low]<=nums[mid]){
            ans = min(ans , nums[low]);
            low=mid+1;
            }
            // right half sorted
            else  {
                ans = min(ans , nums[mid]);
                high = mid - 1 ;
            } 
            
        }


        return  ans ;
    }
};