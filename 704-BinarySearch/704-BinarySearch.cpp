// Last updated: 7/20/2026, 10:17:21 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n = nums.size();
5        int low=  0 ;
6        int high = n-1;
7        int ans = -1 ;
8        while(low<=high){
9            int mid = (low+high)/2;
10            if(nums[mid]==target){
11                ans=mid;
12                break;
13            }
14            else if (nums[mid]>target){
15                high = mid-1;
16            }
17            else low = mid+1;
18        }
19        return ans ;
20    }
21};