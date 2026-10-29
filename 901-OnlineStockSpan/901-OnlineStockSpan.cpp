// Last updated: 10/29/2026, 4:52:15 PM
1class StockSpanner {
2    stack<pair<int, int>> st;
3
4public:
5    StockSpanner() {}
6
7    int next(int price) {
8        int span = 1;
9        while (!st.empty() && st.top().first <= price) {
10            span += st.top().second;
11            st.pop();
12        }
13        st.push({price, span});
14        return span;
15    }
16};
17