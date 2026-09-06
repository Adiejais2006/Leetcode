// Last updated: 9/6/2026, 5:17:17 PM
1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        int n = nums.size();
5        vector<int>freq(101,0);
6        for(int i:nums) {
7            freq[i]++;
8        }
9        for(int i=1;i<101;i++) {
10            freq[i]+=freq[i-1];
11        }
12        vector<int>result(n);
13        for(int i=0;i<n;i++) {
14            if(nums[i]==0) {
15                result[i]=0;
16            }
17            else {
18                result[i]=freq[nums[i]-1];
19            }
20        }
21        return result;        
22    }
23};