// Last updated: 7/18/2026, 1:58:54 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]]++;
        }

        int dup = 0 ;
        for(auto it : mpp){
            if(it.second > 1){
                dup++;
            }
        }

        if(dup == 0) return 0;

        int op = 0 ;

        for(int i = 0 ; i < n ; i = i + 3){
            op++;

            for(int k = i ; k < min(i + 3 , n) ; k++ ){
                int val = nums[k];
                mpp[val]--;

                if(mpp[val] == 1){
                    dup--;
                }
            }

            if(dup == 0){
                break;
            }
        }

        return op;
    }
};
