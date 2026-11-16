// Last updated: 11/16/2026, 5:15:46 PM
1class Solution {
2    double helper(int speed , vector<int>&dist){
3        double sum = 0 ;
4        int n = dist.size();
5        for(int i = 0 ; i<n-1 ; i++){
6           sum+= (double)dist[i]/speed; 
7           sum=ceil(sum);
8        }
9        sum += (double)dist[n - 1] / speed;
10        return sum ;
11    }
12public:
13    int minSpeedOnTime(vector<int>& dist, double hour) {
14        if (hour <= dist.size() - 1)
15            return -1;
16        int n = dist.size();
17        double low = 1;
18        double high = 10000000;
19        while(low<=high){
20            int mid = low +(high-low)/2;
21            double  timeTaken = helper(mid,dist);
22            if(timeTaken>hour) low=mid+1;
23            else high=mid-1;
24        }
25        return low;
26    }
27};