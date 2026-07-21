// Last updated: 7/21/2026, 3:00:50 PM
1class Solution {
2    long long helper(vector<int>& time, long long timeT, int totalTrips) {
3        long long trips = 0;
4        for (auto it : time) {
5            trips += timeT / it;
6           
7        }
8        return trips;
9    }
10
11public:
12    long long minimumTime(vector<int>& time, int totalTrips) {
13        long long mini = INT_MAX;
14        for (auto it : time) {
15            if(mini>it){
16                mini = it;
17            }
18        }
19        long long low = mini;
20        long long high = mini * totalTrips;
21
22        while (low <= high) {
23            long long mid = low + (high - low) / 2;
24            long long trips = helper(time, mid, totalTrips);
25            if (trips >= totalTrips) {
26                high = mid - 1;
27            } else
28                low = mid + 1;
29        }
30        return low;
31    }
32};