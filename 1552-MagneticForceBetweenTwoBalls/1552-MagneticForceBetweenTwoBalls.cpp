// Last updated: 9/26/2026, 2:47:54 PM
1class Solution {
2public:
3    int maxDistance(vector<int>& position, int m) {
4        sort(position.begin(), position.end());
5        int lo = 1;
6        int hi = (position.back() - position[0]) / (m - 1);
7        int ans = 1;
8        while (lo <= hi) {
9            int mid = lo + (hi - lo) / 2;
10            if (canWePlace(position, mid, m)) {
11                ans = mid;
12                lo = mid + 1;
13            } else {
14                hi = mid - 1;
15            }
16        }
17        return ans;
18    }
19
20private:
21    bool canWePlace(const vector<int>& arr, int dist, int balls) {
22        int countBalls = 1;
23        int lastPlaced = arr[0];
24        for (int i = 1; i < arr.size(); i++) {
25            if (arr[i] - lastPlaced >= dist) {
26                countBalls++;
27                lastPlaced = arr[i];
28            }
29            if (countBalls >= balls) {
30                return true;
31            }
32        }
33        return false;
34    }
35};