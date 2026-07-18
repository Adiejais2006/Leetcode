// Last updated: 7/18/2026, 2:04:22 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
          int freq=0;
        int count=0;
        for(int i=0;i<nums.size();i++){

            if(nums[i]==1){
                count++;
                if(count>freq) freq=count;
            }

            else if(nums[i]==0){
                count=0;
            }


        }

        return freq;

    }
};