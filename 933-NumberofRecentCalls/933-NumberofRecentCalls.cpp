// Last updated: 9/4/2026, 4:50:08 PM
1class RecentCounter {
2    vector<int>nums;
3public:
4    RecentCounter() {
5    }
6    
7    int ping(int t) {
8        nums.push_back(t);
9        int low = t - 3000;
10        int i = 0 ;
11        int cnt = 0 ; 
12        while(i<nums.size()){
13            if(nums[i]>=low && nums[i] <= t ){
14                cnt++;
15            }
16            i++;
17        } 
18        return cnt;
19    }
20};
21
22