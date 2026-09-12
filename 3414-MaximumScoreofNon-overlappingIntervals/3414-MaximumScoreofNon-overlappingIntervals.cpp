// Last updated: 9/12/2026, 9:44:03 AM
1class Solution {
2public:
3    using P = pair<long long, vector<int>>;
4
5    vector<tuple<int,int,int>> intervals;
6    vector<int> nextIndex;
7    vector<vector<P>> dp;
8    map<tuple<int,int,int>, int> originalIndex;
9
10    // dp[i][k] = best (negative weight, indices) 
11    P solve(int i, int k){
12        if(i == intervals.size() || k == 0) return {0, {}};
13
14        if(dp[i][k].first != -1) return dp[i][k];
15
16        P skip = solve(i + 1, k);
17
18        auto [left, right, weight] = intervals[i];
19
20        P take = solve(nextIndex[i], k - 1);
21
22        take.first -= weight; // ref : step 5 if you confuse
23        take.second.push_back(originalIndex[{left, right, weight}]);
24        sort(take.second.begin(), take.second.end());
25
26        return dp[i][k] = min(skip, take);
27    }
28
29    vector<int> maximumWeight(vector<vector<int>>& a) {
30        // map : stored in sorted order
31        for(int i = 0; i < a.size(); i++){
32             if (originalIndex.find({a[i][0], a[i][1], a[i][2]})
33                != originalIndex.end()){
34                    continue; //Skip Dublicate
35            }
36            originalIndex[{a[i][0], a[i][1], a[i][2]}] = i;
37        }
38
39        for(auto &[interval, index] : originalIndex){
40            intervals.push_back(interval);
41        }
42
43        int n = intervals.size();
44        nextIndex.resize(n);
45
46        // Next Valid Interval (non-overlapping)
47        for(int i = 0; i < n; i++){
48            auto [left, right, weight] = intervals[i];
49
50            nextIndex[i] = upper_bound(
51                intervals.begin(),
52                intervals.end(),
53                make_tuple(right, INT_MAX, INT_MAX)
54            ) - intervals.begin();
55        }
56
57        dp.assign(n, vector<P>(5, {-1, {}}));
58
59        return solve(0, 4).second;
60    }
61};