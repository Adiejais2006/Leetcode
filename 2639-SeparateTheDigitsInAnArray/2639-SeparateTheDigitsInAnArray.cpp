// Last updated: 7/18/2026, 2:00:28 PM
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            vector<int>digits;
            while(num>0){
                int digit=num%10;
                digits.push_back(digit);
                num/=10;
            }
            for(int j=digits.size()-1;j>=0;j--){
                ans.push_back(digits[j]);
            }
        }
        return ans;
    }
};