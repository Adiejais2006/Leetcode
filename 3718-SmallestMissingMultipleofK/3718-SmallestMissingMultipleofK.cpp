// Last updated: 8/25/2026, 10:26:40 PM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        unordered_map<int,int>mpp;
5        for(auto it:nums)mpp[it]++;
6        int i = 0 ;
7        while(true){
8            i+= k ;
9            if(mpp.find(i)==mpp.end())return i ;
10        }
11        return  i ;
12    }
13};