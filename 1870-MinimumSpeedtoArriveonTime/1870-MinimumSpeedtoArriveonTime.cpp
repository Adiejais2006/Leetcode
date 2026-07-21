// Last updated: 7/21/2026, 7:38:27 PM
1class Solution {
2    double helper(vector<int>& dist, double hour, double speed) {
3        double hours = 0;
4        int n = dist.size();
5        for (int i = 0; i < dist.size() - 1; i++) {
6            double time = ((double)dist[i] / speed);
7            hours += time;
8            hours = ceil(hours);
9        }
10        hours += (double)dist[n - 1] / speed;
11        return hours;
12    }
13
14public:
15    int minSpeedOnTime(vector<int>& dist, double hour) {
16        if(hour<=dist.size()-1) return -1 ;
17        int low = 1;
18        int high = 10000000;
19        while (low <= high) {
20            int mid = low + (high - low) / 2;
21            double timeTaken = helper(dist, hour, mid);
22            if (timeTaken <= hour) {
23                high = mid - 1;
24            } else  {
25                low = mid + 1;
26            }
27        }
28       
29        return low;
30    }
31};