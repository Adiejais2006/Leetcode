// Last updated: 7/18/2026, 2:03:08 PM
class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        if (target <= startFuel)
            return 0;
        int stops = 0;
        int n = stations.size();
        sort(stations.begin(), stations.end());
        priority_queue<int> pq;
        int i = 0;
        while (i < n || !pq.empty()) {

            while (i < n && startFuel >= stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1 ;
            auto it = pq.top();
            pq.pop();
            startFuel = startFuel + it;
            stops++;
            if (startFuel >= target)
                return stops;
        }
        return -1;
    }
};