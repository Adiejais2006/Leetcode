// Last updated: 10/18/2026, 6:16:25 PM
1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n = nums.size();
5         int i =0;
6         while( i<n){
7            int  x = nums[i];
8            if( x>0 && x<=n && nums[i]!=nums[x-1] ) {swap( nums[i], nums[x-1]);}
9             else i++;
10        }
11        for( int i =0;i<n;i++){
12            if( nums[i]!=i+1) return i+1;
13        }
14         return n+1;
15         
16        
17    }
18};