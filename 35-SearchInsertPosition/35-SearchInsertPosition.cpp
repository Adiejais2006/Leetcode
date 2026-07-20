// Last updated: 7/20/2026, 10:30:38 PM
1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4         int n = nums.size();
5        int low=  0 ;
6        int high = n-1;
7        int ans = -1 ;
8        while(low<=high){
9            int mid = (low+high)/2;
10            if(nums[mid]==target){
11                return mid;
12            }
13            else if (nums[mid]>target){
14                high = mid-1;
15            }
16            else low = mid+1;
17        }
18        return low ;
19    }
20};