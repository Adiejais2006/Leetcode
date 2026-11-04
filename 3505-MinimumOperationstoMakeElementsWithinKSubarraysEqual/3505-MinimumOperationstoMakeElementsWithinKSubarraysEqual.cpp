// Last updated: 11/4/2026, 2:39:15 PM
1class Window {
2    multiset<int> s;
3    multiset<int>::iterator mid;  // the (h+1)-th smallest: everything before it is the low half
4    long long low, total;
5    int odd;
6
7public:
8    Window(vector<int>::const_iterator first, vector<int>::const_iterator last)
9        : s(first, last), odd(s.size() & 1) {
10        mid = next(s.begin(), s.size() / 2);
11        low = accumulate(s.begin(), mid, 0LL);
12        total = accumulate(s.begin(), s.end(), 0LL);
13    }
14
15    long long cost() const {  // larger half minus smaller half
16        return total - 2 * low - odd * *mid;
17    }
18
19    long long slide(int out, int in) {
20        s.insert(in);
21        if (in < *mid)  // in joins the low half and pushes its largest up
22            low += in - *--mid;
23        if (out < *mid) {  // out leaves the low half: mid moves down into it
24            low += *mid++ - out;
25            s.erase(s.find(out));
26        } else if (out == *mid) {
27            mid = s.erase(mid);
28        } else {
29            s.erase(s.find(out));
30        }
31        total += in - out;
32        return cost();
33    }
34};
35
36class Solution {
37public:
38    long long minOperations(vector<int>& nums, int x, int k) {
39        int n = nums.size();
40        Window win(nums.begin(), nums.begin() + x);
41        vector<long long> cost{win.cost()};
42        for (int i = x; i < n; ++i)
43            cost.push_back(win.slide(nums[i - x], nums[i]));
44
45        vector<long long> best(n + 1);  // best[i]: min ops for the windows placed so far inside nums[0..i)
46        for (int j = 0; j < k; ++j) {
47            vector<long long> layer(n + 1, LLONG_MAX / 2);
48            for (int i = x; i <= n; ++i)
49                layer[i] = min(layer[i - 1], best[i - x] + cost[i - x]);
50            best = move(layer);
51        }
52        return best[n];
53    }
54};