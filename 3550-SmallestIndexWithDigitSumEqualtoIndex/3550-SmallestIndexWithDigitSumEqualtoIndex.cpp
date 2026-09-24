// Last updated: 9/24/2026, 11:45:53 AM
1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        int n = nums.size();
5        for(int i = 0 ; i<n ; i++){
6            int sum = 0 ;
7            int orig = nums[i];
8            while(orig!=0){
9                sum+= orig%10;
10                orig=orig/10;
11            }
12            if(i==sum) return i ;
13        }
14        return -1;
15    }
16};