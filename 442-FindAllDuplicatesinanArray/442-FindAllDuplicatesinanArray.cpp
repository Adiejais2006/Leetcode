// Last updated: 9/13/2026, 3:03:18 PM
1class Solution {
2public:
3    vector<int> findDuplicates(vector<int>& nums) {
4        unordered_map<int, int> mpp;
5        for (auto it : nums) {
6            mpp[it]++;
7        }
8        vector<int>ans;
9        for(auto it :mpp){
10            if(it.second==2){
11                ans.push_back(it.first);
12            }
13        }
14        return ans;
15    }
16};