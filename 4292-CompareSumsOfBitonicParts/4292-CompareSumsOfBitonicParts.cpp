// Last updated: 7/18/2026, 1:58:43 PM
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long n = nums.size();
        long long maxiind=-1;
        for(int i =1 ; i<n ;i++){
            if(nums[i]>nums[i-1]){
                maxiind = i;
            }
            else {
                break;
            }
        }

        long long lsum =0;
        long long rsum=0;
        
        for(int i = 0 ; i<=maxiind ;i++){
            lsum+=nums[i];
        }
        for(int j = maxiind ; j< n; j++){
            rsum+=nums[j];
        }
        if(lsum>rsum) return 0;
        else if (lsum<rsum) return 1 ;
        return -1;
    }
};