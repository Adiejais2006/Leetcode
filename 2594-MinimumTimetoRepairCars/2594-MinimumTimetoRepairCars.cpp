// Last updated: 11/4/2026, 7:07:43 PM
1class Solution {
2private:
3    bool helper(long long time, vector<int>& ranks, int totalcars) {
4        long long repair = 0;
5        for (auto it : ranks) {
6            repair += sqrtl(time / it); 
7        }
8        return repair >= totalcars;
9    }
10public:
11    long long repairCars(vector<int>& ranks, int cars) {
12        long long mini = INT_MAX; 
13        for (auto it : ranks) {
14            mini = min(mini, (long long)it);
15        }
16        long long low = 1;
17        long long high = mini * cars * cars; 
18        long long ans = high;
19        while (low <= high) {
20            long long mid = low + (high - low) / 2;
21            if (helper(mid, ranks, cars)) {
22                ans = mid;         
23                high = mid - 1;
24            } else {
25                low = mid + 1;   
26            }
27        }
28        return ans;
29    }
30};
31