// Last updated: 7/18/2026, 1:58:42 PM
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();    
        vector<int> ans(n);
        int odd = 0 ;
        int even = 0 ;
        int i = n-1;

        while(i>=0){
            if(nums[i]%2==0){
                ans[i]=odd;
            }
            else ans[i] =even;
            if(nums[i]%2==0) even++;
            else odd++;
            i--;
        }

        return ans ;
    }
};