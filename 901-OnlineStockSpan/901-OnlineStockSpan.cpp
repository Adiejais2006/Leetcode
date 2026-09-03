// Last updated: 9/3/2026, 3:31:22 PM
1class StockSpanner {
2    stack<pair<int, int>> st;
3    int day;
4public:
5    StockSpanner() {
6        day = 0;
7    }
8    int next(int price) {
9        while (!st.empty() && st.top().first <= price)
10            st.pop();
11        int ans;
12        if (st.empty())
13            ans = day + 1;
14        else
15            ans = day - st.top().second;
16        st.push({price, day});
17        day++;
18        return ans;
19    }
20};