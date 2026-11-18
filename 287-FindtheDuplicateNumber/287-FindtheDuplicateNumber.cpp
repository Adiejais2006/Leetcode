// Last updated: 11/18/2026, 1:41:31 PM
1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4       unordered_map<int,int>mpp;
5       for(auto it:nums){
6        mpp[it]++;
7        if(mpp[it]==2)return it;
8       }
9       return -1;
10    }
11};