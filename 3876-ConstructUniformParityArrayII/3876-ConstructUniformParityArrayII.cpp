// Last updated: 9/3/2026, 11:41:04 AM
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int mini = INT_MAX;
5        for (auto it : nums1) {
6            mini = min(it, mini);
7        }
8        if(mini%2==0){
9            for(auto it:nums1){
10                if(it%2==1) return false;
11            }
12        }
13        return true;
14    }
15};