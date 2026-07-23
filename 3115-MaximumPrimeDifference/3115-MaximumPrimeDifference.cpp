// Last updated: 7/24/2026, 12:23:26 AM
1class Solution {
2public:
3    bool isPrime(long long n) {
4        if (n <= 1) return false;
5        if (n <= 3) return true;
6        if (n % 2 == 0 || n % 3 == 0) return false;
7        for (long long i = 5; i * i <= n; i += 6) {
8            if (n % i == 0 || n % (i + 2) == 0) {
9                return false;
10            }
11        }    
12        return true;
13    }
14    int maximumPrimeDifference(vector<int>& nums) {
15        int i;
16        for(i=0;i<nums.size();i++) {
17            if (isPrime(nums[i])) break;
18        }
19        for(int j=nums.size()-1;j>=0;j--) {
20            if (isPrime(nums[j])) return j-i;
21        }
22        return -1;        
23    }
24};