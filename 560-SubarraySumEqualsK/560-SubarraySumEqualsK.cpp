// Last updated: 10/31/2026, 3:42:39 PM
1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int n = nums.size();
5        unordered_map<int,int>mpp;
6        mpp[0]=1;
7        int sum = 0 ;
8        int ans= 0 ; 
9        for(int i = 0 ;i<n ; i++){
10            sum+=nums[i];
11            int rem = sum-k;
12            if(mpp.find(rem)!=mpp.end()){
13                ans+=mpp[rem];
14            }
15            mpp[sum]++;
16        }   
17        return ans ;
18    }
19};