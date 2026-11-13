// Last updated: 11/13/2026, 12:14:28 PM
1class Solution {
2public:
3    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
4        int n = gas.size();
5        int totalgas = 0;
6        int totalcost = 0;
7        for (auto it : gas)
8            totalgas += it;
9        for (auto it : cost)
10            totalcost += it;
11        if (totalcost > totalgas)
12            return -1;
13        int ans = 0;
14        int sum = 0;
15        for(int i =0 ; i<n ; i++){
16            sum+= gas[i] - cost[i];
17            if(sum<0){
18                ans=i+1;
19                sum = 0 ; 
20            }
21        }
22        return ans;
23    }
24};