// Last updated: 11/6/2026, 6:22:14 PM
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        int n = nums.size();
5         priority_queue<int,vector<int>,greater<int>> pq;
6         int i = 0 ; 
7         for( i  ; i< k ; i++) pq.push(nums[i]);
8         for(i ; i<n ; i++){
9            if(nums[i]>pq.top()){
10                pq.pop();
11                pq.push(nums[i]);
12            }
13         }
14         return pq.top();
15    }
16};