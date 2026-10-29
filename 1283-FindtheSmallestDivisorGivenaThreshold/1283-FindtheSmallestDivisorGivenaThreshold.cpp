// Last updated: 10/29/2026, 4:22:52 PM
1class Solution {
2    int helper(int divisor , vector<int>&nums){
3        int sum = 0 ;
4        for(auto it:nums){
5              sum += (it + divisor - 1) / divisor;
6        }
7        return sum ;
8    }
9public:
10    int smallestDivisor(vector<int>& nums, int threshold) {
11        int maxu =INT_MIN;
12        int mini = INT_MAX;
13        for(auto it:nums){
14            mini = min(mini,it);
15            maxu = max(maxu,it);
16        }
17        int low = 1;
18        int high = maxu;
19        while(low<=high){
20            int mid = low + (high-low)/2;
21            int result = helper(mid,nums);
22            if(result>threshold) low=mid+1;
23            else high = mid-1;
24        } 
25        return low;
26    }
27};