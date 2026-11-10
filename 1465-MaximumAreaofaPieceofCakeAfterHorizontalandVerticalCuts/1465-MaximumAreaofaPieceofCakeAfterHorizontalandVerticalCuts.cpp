// Last updated: 11/10/2026, 11:03:08 PM
1class Solution {
2    const long long int mod = 1000000007;
3
4public:
5    int maxArea(int hh, int ww, vector<int>& h, vector<int>& v) {
6        sort(h.begin(), h.end());
7        sort(v.begin(), v.end());
8        vector<int> heights = {h[0]};
9        int nh = h.size();
10        for (int i = 1; i < nh; i++) {
11            heights.push_back(h[i] - h[i - 1]);
12        }
13        heights.push_back(hh - h[nh - 1]);
14        vector<int> lengths = {v[0]};
15        int nv = v.size();
16        for (int i = 1; i < nv; i++) {
17            lengths.push_back(v[i] - v[i - 1]);
18        }
19        lengths.push_back(ww - v[nv - 1]);
20        long long int a = *max_element(heights.begin(), heights.end());
21        long long int b = *max_element(lengths.begin(), lengths.end());
22        return (int)(a % mod * b % mod);
23    }
24};