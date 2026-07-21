// Last updated: 7/21/2026, 3:00:38 PM
1class Solution {
2    long long helper(vector<int>& time, long long timeT, int totalTrips) {
3        long long trips = 0;
4        for (auto it : time) {
5            trips += timeT / it;
6            if (trips >= totalTrips)
7                return trips;
8        }
9        return trips;
10    }
11
12public:
13    long long minimumTime(vector<int>& time, int totalTrips) {
14        long long mini = INT_MAX;
15        for (auto it : time) {
16            if(mini>it){
17                mini = it;
18            }
19        }
20        long long low = mini;
21        long long high = mini * totalTrips;
22
23        while (low <= high) {
24            long long mid = low + (high - low) / 2;
25            long long trips = helper(time, mid, totalTrips);
26            if (trips >= totalTrips) {
27                high = mid - 1;
28            } else
29                low = mid + 1;
30        }
31        return low;
32    }
33};