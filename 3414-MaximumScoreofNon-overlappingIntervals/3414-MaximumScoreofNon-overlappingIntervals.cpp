// Last updated: 9/12/2026, 9:44:35 AM
1class Solution {
2public:
3    using P = pair<long long, vector<int>>;
4    vector<tuple<int,int,int>> intervals;
5    vector<int> nextIndex;
6    vector<vector<P>> dp;
7    map<tuple<int,int,int>, int> originalIndex;
8    P solve(int i, int k){
9        if(i == intervals.size() || k == 0) return {0, {}};
10        if(dp[i][k].first != -1) return dp[i][k];
11        P skip = solve(i + 1, k);
12        auto [left, right, weight] = intervals[i];
13        P take = solve(nextIndex[i], k - 1);
14        take.first -= weight; // ref : step 5 if you confuse
15        take.second.push_back(originalIndex[{left, right, weight}]);
16        sort(take.second.begin(), take.second.end());
17        return dp[i][k] = min(skip, take);
18    }
19    vector<int> maximumWeight(vector<vector<int>>& a) {
20        for(int i = 0; i < a.size(); i++){
21             if (originalIndex.find({a[i][0], a[i][1], a[i][2]})
22                != originalIndex.end()){
23                    continue; 
24            }
25            originalIndex[{a[i][0], a[i][1], a[i][2]}] = i;
26        }
27        for(auto &[interval, index] : originalIndex){
28            intervals.push_back(interval);
29        }
30        int n = intervals.size();
31        nextIndex.resize(n);
32        for(int i = 0; i < n; i++){
33            auto [left, right, weight] = intervals[i];
34            nextIndex[i] = upper_bound(
35                intervals.begin(),
36                intervals.end(),
37                make_tuple(right, INT_MAX, INT_MAX)
38            ) - intervals.begin();
39        }
40        dp.assign(n, vector<P>(5, {-1, {}}));
41        return solve(0, 4).second;
42    }
43};